//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSMutableDictionary;

__attribute__((visibility("hidden")))
@interface OAKVONotificationCenter : NSObject
{
    NSMutableDictionary *listeners;
}

+ (id)defaultCenter;
@property(retain, nonatomic) NSMutableDictionary *listeners; // @synthesize listeners;
- (void)removeObserver:(id)arg1 target:(id)arg2 keyPath:(id)arg3 selector:(SEL)arg4;
- (void)addListener:(id)arg1;
- (id)listenerKeyForObserver:(id)arg1 target:(id)arg2 keyPath:(id)arg3 selector:(SEL)arg4;
- (void)dealloc;

@end
