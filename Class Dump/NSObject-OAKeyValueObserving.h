//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@interface NSObject (OAKeyValueObserving)
- (void)removeObserver:(id)arg1 keyPath:(id)arg2 selector:(SEL)arg3;
- (void)addObserver:(id)arg1 forKeyPath:(id)arg2 selector:(SEL)arg3 userInfo:(id)arg4 options:(unsigned long long)arg5;
- (void)addObserver:(id)arg1 forKeyPath:(id)arg2 selector:(SEL)arg3;
- (void)addObserver:(id)arg1 forKeyPath:(id)arg2 selectorWithNewValue:(SEL)arg3;
- (void)addObserver:(id)arg1 forKeyPath:(id)arg2 selectorWithoutArguments:(SEL)arg3;
@end

