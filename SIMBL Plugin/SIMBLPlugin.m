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
    return self;
}

+ (void)load;
{
    SWIZZLE(@"GBCommitViewController", updateHeaderSize, SIMBL_updateHeaderSize);
    SWIZZLE(@"GBStageViewController", updateHeader, SIMBL_updateHeader);
    SWIZZLE(@"GBCommitCell", drawSyncStatusIconInRect:, SIMBL_drawSyncStatusIconInRect:);
}

@end
