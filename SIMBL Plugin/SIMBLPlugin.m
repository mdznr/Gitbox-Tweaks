//
// SIMBLPlugin.m
// SIMBL Plugin
//
// Created by Anton Sotkov on 28.05.12.
// Copyright 2012 MirrorMirror. All rights reserved.
//

#import "SIMBLPlugin.h"
#import "JRSwizzle.h"

@implementation NSObject (SIMBLPlugin)



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

+ (void)load;
{
    
}

@end
