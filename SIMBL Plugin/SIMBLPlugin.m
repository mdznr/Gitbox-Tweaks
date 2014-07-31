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

@implementation NSObject (SIMBLPlugin)

- (void)SIMBL_updateHeaderSize;
{
    GBCommitViewController *commitViewController = (GBCommitViewController *)self;
    commitViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self SIMBL_updateHeaderSize];
}

- (void)SIMBL_updateHeader;
{
    GBStageViewController *stageViewController = (GBStageViewController *)self;
    stageViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self SIMBL_updateHeader];
}

- (void)SIMBL_drawSyncStatusIconInRect:(NSRect)rect;
{
    GBCommitCell *cell = (GBCommitCell *)self;
    CGFloat dimensions = 8;
    CGFloat margin = 5;
    NSBezierPath *circle = [[NSBezierPath alloc] init];
    [circle appendBezierPathWithOvalInRect:NSMakeRect(rect.origin.x - dimensions - margin, rect.origin.y + margin, dimensions, dimensions)];
    [[[SIMBLPlugin sharedPlugin] colorForSyncStatus:cell.commit.syncStatus] setFill];
    [circle fill];
}

- (NSImage *)SIMBL_image;
{
    NSImage *image = [self SIMBL_image];
    return [[SIMBLPlugin sharedPlugin] replacementImages][image.name] ? : image;
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
        @"GBSidebarSubmoduleMissingIcon": [self imageNamed:@"GBSidebarSubmoduleMissingIcon"]
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
    SWIZZLE(@"GBCommitViewController", updateHeaderSize, SIMBL_updateHeaderSize);
    SWIZZLE(@"GBStageViewController", updateHeader, SIMBL_updateHeader);
    SWIZZLE(@"GBCommitCell", drawSyncStatusIconInRect:, SIMBL_drawSyncStatusIconInRect:);
    SWIZZLE(@"GBSidebarCell", image, SIMBL_image);
}

- (void)setupElements;
{
    GBAppDelegate *delegate = (GBAppDelegate *)[NSApp delegate];

    NSToolbar *toolbar = delegate.windowController.toolbarController.toolbar;

    NSToolbarItem *plusToolbarItem = toolbar.items[0];
    plusToolbarItem.image = [self imageNamed:@"GBToolbarPlus"];

    NSToolbarItem *gearToolbarItem = toolbar.items[1];
    gearToolbarItem.image = [self imageNamed:@"GBToolbarGear"];

    GBSidebarController *sidebar = delegate.windowController.sidebarController;
    [sidebar updateContents];
}

@end
