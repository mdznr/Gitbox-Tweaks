//
// SIMBLPlugin.m
// SIMBL Plugin
//
// Created by Anton Sotkov on 28.05.12.
// Copyright 2012 MirrorMirror. All rights reserved.
//

#import "SIMBLPlugin.h"
#import "JRSwizzle.h"
#import "GBCommitViewController.h"
#import "GBStageViewController.h"
#import "GBCommitCell.h"
#import "GBStage.h"
#import "GBSidebarItem.h"
#import "GBAppDelegate.h"
#import "GBRootController.h"
#import "GBSidebarController.h"
#import "GBMainWindowController.h"
#import "GBToolbarController.h"
#import "GBGreyGradientView.h"
#import "GBMainWindowController.h"

@implementation NSObject (SIMBLPlugin)

- (void)GBCommitViewController_updateHeaderSize;
{
    GBCommitViewController *commitViewController = (GBCommitViewController *)self;
    commitViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self GBCommitViewController_updateHeaderSize];
}

- (void)GBStageViewController_updateHeaderSizeAnimating:(BOOL)animating;
{
    GBStageViewController *stageViewController = (GBStageViewController *)self;
    stageViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self GBStageViewController_updateHeaderSizeAnimating:animating];
}

- (void)GBCommitCell_drawSyncStatusIconInRect:(NSRect)rect;
{
    GBCommitCell *cell = (GBCommitCell *)self;
    CGFloat dimensions = 8;
    CGFloat margin = 5;
    NSBezierPath *circle = [[NSBezierPath alloc] init];
    [circle appendBezierPathWithOvalInRect:NSMakeRect(rect.origin.x - dimensions - margin, rect.origin.y + margin, dimensions, dimensions)];
    [[[SIMBLPlugin sharedPlugin] colorForSyncStatus:cell.commit.syncStatus] setFill];
    [circle fill];
}

- (NSImage *)GBSidebarCell_image;
{
    NSImage *image = [self GBSidebarCell_image];
    return [[SIMBLPlugin sharedPlugin] replacementImages][image.name] ? : image;
}

- (double)GBToolbarController_sidebarPadding;
{
    double padding = [self GBToolbarController_sidebarPadding];

    if (rint(NSAppKitVersionNumber) > NSAppKitVersionNumber10_9) {
        GBToolbarController *toolbarController = (GBToolbarController *)self;
        if (toolbarController.window.titleVisibility == NSWindowTitleHidden)
            padding -= 70.0;
    }

    return padding;
}

+ (NSImage *)NSImage_imageNamed:(NSString *)name;
{
    NSImage *image = [self NSImage_imageNamed:name];
    return [[SIMBLPlugin sharedPlugin] replacementImages][image.name.stringByDeletingPathExtension] ? : image;
}

@end

@implementation SIMBLPlugin

+ (instancetype)sharedPlugin;
{
    static id sharedPlugin = nil;

    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedPlugin = [[self alloc] init];
    });

    return sharedPlugin;
}

- (NSColor *)colorForSyncStatus:(int)syncStatus;
{
    switch (syncStatus) {
        default: return [NSColor clearColor];
        case 1: return [NSColor colorWithRed:0.28f green:0.80f blue:1.00f alpha:1.0f]; // Blue (Unmerged)
        case 2: return [NSColor colorWithRed:0.47f green:0.84f blue:0.31f alpha:1.0f]; // Green (Unpushed)
    }
}

- (NSImage *)imageNamed:(NSString *)name;
{
    return [[NSImage alloc] initWithContentsOfURL:[self.bundle URLForImageResource:name]];
}

- (NSBundle *)bundle;
{
    return [NSBundle bundleForClass:self.class];
}

- (instancetype)init;
{
    self = [super init];
    self.commitMessageFont = [NSFont fontWithName:@"Menlo" size:12];
    self.replacementImages = @{
        @"GBSidebarGroupIcon": [self imageNamed:@"GBSidebarGroupIcon"],
        @"GBSidebarRepositoryIcon": [self imageNamed:@"GBSidebarRepositoryIcon"],
        @"GBSidebarSubmoduleIcon": [self imageNamed:@"GBSidebarSubmoduleIcon"],
        @"GBSidebarSubmoduleMissingIcon": [self imageNamed:@"GBSidebarSubmoduleMissingIcon"],
        @"GBBadgeTagLeft": [self imageNamed:@"GBBadgeTagLeft"],
        @"GBBadgeTagCenter": [self imageNamed:@"GBBadgeTagCenter"],
        @"GBBadgeTagRight": [self imageNamed:@"GBBadgeTagRight"],
    };
    return self;
}

+ (void)load;
{
    SIMBLPlugin *plugin = [SIMBLPlugin sharedPlugin];
    [plugin swizzleMethods];
    [plugin setupElements];
}

- (void)swizzleMethods;
{
    SWIZZLE(@"GBCommitViewController", updateHeaderSize, GBCommitViewController_updateHeaderSize);
    SWIZZLE(@"GBStageViewController", updateHeaderSizeAnimating:, GBStageViewController_updateHeaderSizeAnimating:);
    SWIZZLE(@"GBCommitCell", drawSyncStatusIconInRect:, GBCommitCell_drawSyncStatusIconInRect:);
    SWIZZLE(@"GBSidebarCell", image, GBSidebarCell_image);
    SWIZZLE(@"GBToolbarController", sidebarPadding, GBToolbarController_sidebarPadding);
    SWIZZLE_CLASS(@"NSImage", imageNamed:, NSImage_imageNamed:);
}

- (void)setupElements;
{
    GBAppDelegate *delegate = (GBAppDelegate *)[NSApp delegate];

    GBSidebarController *sidebar = delegate.windowController.sidebarController;
    [sidebar updateContents];

    NSToolbar *toolbar = delegate.windowController.toolbarController.toolbar;

    NSToolbarItem *plusToolbarItem = toolbar.items[0];
    CGSize size = plusToolbarItem.minSize;
    size.width += 6;
    plusToolbarItem.minSize = size;
    plusToolbarItem.maxSize = size;
    NSImage *plus = [self imageNamed:@"GBToolbarPlus"];
    plus.template = YES;
    NSPopUpButton *plusButton = (NSPopUpButton *)plusToolbarItem.view;
    [plusButton.menu.itemArray[0] setImage:plus];
    NSPopUpButtonCell *plusCell = plusButton.cell;
    plusCell.imageScaling = NSImageScaleNone;
    plusCell.arrowPosition = NSPopUpArrowAtBottom;

    NSImage *gear = [self imageNamed:@"GBToolbarGear"];
    gear.template = YES;
    NSToolbarItem *gearToolbarItem = toolbar.items[1];
    gearToolbarItem.image = gear;

    if (rint(NSAppKitVersionNumber) > NSAppKitVersionNumber10_9) {
        GBMainWindowController *windowController = delegate.windowController;
        windowController.window.titleVisibility = NSWindowTitleHidden;
    }
}

@end
