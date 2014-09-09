//
// SIMBLPlugin.h
// SIMBL Plugin
//
// Created by Anton Sotkov on 28.05.12.
// Copyright 2012 MirrorMirror. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface SIMBLPlugin : NSObject

+ (SIMBLPlugin *)sharedPlugin;

- (NSImage *)imageNamed:(NSString *)name;
- (NSColor *)colorForSyncStatus:(int)syncStatus;

@property (nonatomic) NSBundle *bundle;
@property (nonatomic) NSFont *commitMessageFont;
@property (nonatomic) NSDictionary *replacementImages;
@property (nonatomic) NSData *headerRTFTemplate;

@end
