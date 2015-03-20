//
// SIMBLPlugin.m
// SIMBL Plugin
//
// Created by Anton Sotkov on 28.05.12.
// Copyright 2012 MirrorMirror. All rights reserved.
//

#import "SIMBLPlugin.h"
#import "JRSwizzle.h"
#import "GBColorLabelPicker.h"
#import "GBColorLabelPickerButton.h"
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
#import "GBSidebarCell.h"
#import "YRKSpinningProgressIndicator.h"

NSString * const GBTweaksDidPromptForCustomIcon = @"GBTweaksDidPromptForCustomIcon";
NSString * const GBTweaksShouldUseCustomIcon = @"GBTweaksShouldUseCustomIcon";

@interface SIMBLPlugin ()

- (void)setupElements;
- (void)setupGearButton;

@end

@implementation NSObject (SIMBLPlugin)

- (void)GBCommitViewController_updateHeaderSize;
{
    GBCommitViewController *commitViewController = (GBCommitViewController *)self;
    commitViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self GBCommitViewController_updateHeaderSize];
}

- (void)GBStageViewController_updateHeader;
{
    GBStageViewController *stageViewController = (GBStageViewController *)self;
    stageViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self GBStageViewController_updateHeader];
}

- (void)GBStageViewController_updateHeaderSizeAnimating:(BOOL)animating;
{
    GBStageViewController *stageViewController = (GBStageViewController *)self;
    stageViewController.messageTextView.font = [[SIMBLPlugin sharedPlugin] commitMessageFont];
    [self GBStageViewController_updateHeaderSizeAnimating:animating];
}

- (id)GBColorLabelPicker_initWithFrame:(NSRect)frame;
{
	frame = NSRectFromCGRect(CGRectMake(frame.origin.x, frame.origin.y, frame.size.width + 28, frame.size.height));
	return [self GBColorLabelPicker_initWithFrame:frame];
}

- (NSRect)GBColorLabelPicker_frameForIndex:(int)index;
{
	return NSRectFromCGRect(CGRectMake(18 + (24 * index), 0, 22, 22));
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

- (void)GBSidebarCell_drawTextInRect:(NSRect)rect;
{
    GBSidebarCell *cell = (GBSidebarCell *)self;
    NSMutableAttributedString *title = cell.attributedStringValue.mutableCopy;
    NSRange range = NSMakeRange(0, title.length);
    [title addAttribute:NSFontAttributeName value:[NSFont systemFontOfSize:[NSFont smallSystemFontSize]] range:range];
    [title drawInRect:rect];
}

- (double)GBToolbarController_sidebarPadding;
{
    double padding = [self GBToolbarController_sidebarPadding];

    if (rint(NSAppKitVersionNumber) > NSAppKitVersionNumber10_9) {
        GBToolbarController *toolbarController = (GBToolbarController *)self;
        if (toolbarController.window.titleVisibility == NSWindowTitleHidden)
            padding -= 76.0;
    }

    return padding;
}

- (NSData *)GBCommitViewController_headerRTFTemplate;
{
    return [[SIMBLPlugin sharedPlugin] headerRTFTemplate];
}

+ (NSImage *)NSImage_imageNamed:(NSString *)name;
{
    NSImage *image = [self NSImage_imageNamed:name];
    return [[SIMBLPlugin sharedPlugin] replacementImages][image.name.stringByDeletingPathExtension] ? : image;
}

- (void)GBMainWindowController_rootControllerDidChangeSelection:(id)sender;
{
    [self GBMainWindowController_rootControllerDidChangeSelection:sender];
    [[SIMBLPlugin sharedPlugin] setupGearButton];
}

- (id)YRKSpinningProgressIndicator_initWithFrame:(NSRect)frame;
{
    YRKSpinningProgressIndicator *indicator = [self YRKSpinningProgressIndicator_initWithFrame:frame];
    [indicator setDrawsBackground:YES];
    return indicator;
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
		@"GBBadgeTagCenter": [self imageNamed:@"GBBadgeTagCenter"],
		@"GBBadgeTagLeft": [self imageNamed:@"GBBadgeTagLeft"],
		@"GBBadgeTagRight": [self imageNamed:@"GBBadgeTagRight"],
		@"GBColorLabelBlue": [self imageNamed:@"GBColorLabelBlue"],
		@"GBColorLabelBlueCorner": [self imageNamed:@"GBColorLabelBlueCorner"],
		@"GBColorLabelClear": [self imageNamed:@"GBColorLabelClear"],
		@"GBColorLabelGray": [self imageNamed:@"GBColorLabelGray"],
		@"GBColorLabelGrayCorner": [self imageNamed:@"GBColorLabelGrayCorner"],
		@"GBColorLabelGreen": [self imageNamed:@"GBColorLabelGreen"],
		@"GBColorLabelGreenCorner": [self imageNamed:@"GBColorLabelGreenCorner"],
		@"GBColorLabelHighlight": [self imageNamed:@"GBColorLabelHighlight"],
		@"GBColorLabelOrange": [self imageNamed:@"GBColorLabelOrange"],
		@"GBColorLabelOrangeCorner": [self imageNamed:@"GBColorLabelOrangeCorner"],
		@"GBColorLabelPurple": [self imageNamed:@"GBColorLabelPurple"],
		@"GBColorLabelPurpleCorner": [self imageNamed:@"GBColorLabelPurpleCorner"],
		@"GBColorLabelRed": [self imageNamed:@"GBColorLabelRed"],
		@"GBColorLabelRedCorner": [self imageNamed:@"GBColorLabelRedCorner"],
		@"GBColorLabelSelection": [self imageNamed:@"GBColorLabelSelection"],
		@"GBColorLabelYellow": [self imageNamed:@"GBColorLabelYellow"],
		@"GBColorLabelYellowCorner": [self imageNamed:@"GBColorLabelYellowCorner"],
        @"GBSidebarGroupIcon": [self imageNamed:@"GBSidebarGroupIcon"],
        @"GBSidebarRepositoryIcon": [self imageNamed:@"GBSidebarRepositoryIcon"],
        @"GBSidebarSubmoduleIcon": [self imageNamed:@"GBSidebarSubmoduleIcon"],
        @"GBSidebarSubmoduleMissingIcon": [self imageNamed:@"GBSidebarSubmoduleMissingIcon"],
		@"GBToolbarGear": [self imageNamed:@"GBToolbarGear"],
		@"GBToolbarMinus": [self imageNamed:@"GBToolbarMinus"],
		@"GBToolbarPlus": [self imageNamed:@"GBToolbarPlus"]
    };
    self.headerRTFTemplate = [NSData dataWithContentsOfURL:[self.bundle URLForResource:@"GBCommitViewControllerHeader" withExtension:@"rtf"]];
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
    /*SWIZZLE(@"GBCommitViewController", updateHeaderSize, GBCommitViewController_updateHeaderSize);
    SWIZZLE(@"GBStageViewController", updateHeader, GBStageViewController_updateHeader);
    SWIZZLE(@"GBStageViewController", updateHeaderSizeAnimating:, GBStageViewController_updateHeaderSizeAnimating:);*/
	SWIZZLE(@"GBColorLabelPicker", initWithFrame:, GBColorLabelPicker_initWithFrame);
	SWIZZLE(@"GBColorLabelPicker", frameForIndex:, GBColorLabelPicker_frameForIndex:);
    SWIZZLE(@"GBCommitViewController", headerRTFTemplate, GBCommitViewController_headerRTFTemplate);
    SWIZZLE(@"GBCommitCell", drawSyncStatusIconInRect:, GBCommitCell_drawSyncStatusIconInRect:);
    SWIZZLE(@"GBSidebarCell", image, GBSidebarCell_image);
    SWIZZLE(@"GBSidebarCell", drawTextInRect:, GBSidebarCell_drawTextInRect:);
    SWIZZLE(@"GBToolbarController", sidebarPadding, GBToolbarController_sidebarPadding);
    SWIZZLE(@"GBMainWindowController", rootControllerDidChangeSelection:, GBMainWindowController_rootControllerDidChangeSelection:);
    SWIZZLE_CLASS(@"NSImage", imageNamed:, NSImage_imageNamed:);
    SWIZZLE(@"YRKSpinningProgressIndicator", initWithFrame:, YRKSpinningProgressIndicator_initWithFrame:);
}

- (void)setupElements;
{
    GBAppDelegate *delegate = (GBAppDelegate *)[NSApp delegate];

    GBSidebarController *sidebar = delegate.windowController.sidebarController;
    [sidebar updateContents];

    if (rint(NSAppKitVersionNumber) > NSAppKitVersionNumber10_9) {
        GBMainWindowController *windowController = delegate.windowController;
        NSRect frame = windowController.window.frame;
        NSURL *representedURL = windowController.window.representedURL;
        windowController.window.representedURL = nil;
        windowController.window.titleVisibility = NSWindowTitleHidden;
        windowController.window.representedURL = representedURL;
        [windowController.window setFrame:frame display:YES];
    }

    NSToolbar *toolbar = delegate.windowController.toolbarController.toolbar;
    NSToolbarItem *plusToolbarItem = toolbar.items[0];
    NSImage *plus = [self imageNamed:@"GBToolbarPlus"];
    plus.template = YES;
    NSPopUpButton *plusButton = (NSPopUpButton *)plusToolbarItem.view;
    [plusButton.menu.itemArray[0] setImage:plus];
    if (rint(NSAppKitVersionNumber) > NSAppKitVersionNumber10_9) {
        // Yosemite Beta 7 seems to not center the image on NSPopUpButton if the arrow is disabled.
        CGSize size = plusToolbarItem.minSize;
        size.width += 6;
        plusToolbarItem.minSize = size;
        plusToolbarItem.maxSize = size;
        NSPopUpButtonCell *plusCell = plusButton.cell;
        plusCell.imageScaling = NSImageScaleNone;
        plusCell.arrowPosition = NSPopUpArrowAtBottom;
    }

    [self setupGearButton];
    [self setupCustomIconIfNecessary];
    [self applyCustomIconIfNecessary];
}

- (void)setupGearButton;
{
    GBAppDelegate *delegate = (GBAppDelegate *)[NSApp delegate];
    NSToolbar *toolbar = delegate.windowController.toolbarController.toolbar;
    NSImage *gear = [self imageNamed:@"GBToolbarGear"];
    gear.template = YES;
    NSToolbarItem *gearToolbarItem = toolbar.items[1];
    gearToolbarItem.image = gear;
}

- (NSImage *)customIcon;
{
    return [self imageNamed:@"Gitbox.icns"];
}

- (void)setupCustomIconIfNecessary;
{
    if ([[NSUserDefaults standardUserDefaults] boolForKey:GBTweaksDidPromptForCustomIcon] == NO) dispatch_async(dispatch_get_main_queue(), ^{
        NSAlert *alert = [[NSAlert alloc] init];
        alert.icon = self.customIcon;
        alert.messageText = @"Would you like use a new icon?";
        alert.informativeText = @"Gitbox Tweaks has a new icon made to match OS X Yosemite.";
        [[alert addButtonWithTitle:@"Use Icon"] setTag:NSModalResponseOK];
        [[alert addButtonWithTitle:@"Cancel"] setTag:NSModalResponseCancel];
        BOOL shouldUseCustomIcon = NO;
        if ([alert runModal] == NSModalResponseOK) {
            [self setupCustomIcon];
            shouldUseCustomIcon = YES;
        }
        [[NSUserDefaults standardUserDefaults] setBool:shouldUseCustomIcon forKey:GBTweaksShouldUseCustomIcon];
        [[NSUserDefaults standardUserDefaults] setBool:YES forKey:GBTweaksDidPromptForCustomIcon];
    });
}

- (void)applyCustomIconIfNecessary;
{
    if ([[NSUserDefaults standardUserDefaults] boolForKey:GBTweaksShouldUseCustomIcon] == NO)
        return;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self setupCustomIcon];
    });
}

- (void)setupCustomIcon;
{
    [[NSWorkspace sharedWorkspace] setIcon:self.customIcon forFile:[[NSBundle mainBundle] bundlePath] options:0];
    [[NSApplication sharedApplication] setApplicationIconImage:self.customIcon];
}

@end
