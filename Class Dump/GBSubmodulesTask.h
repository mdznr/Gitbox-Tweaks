//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBTask.h"

@class NSArray;

__attribute__((visibility("hidden")))
@interface GBSubmodulesTask : GBTask
{
    NSArray *_submodules;
}

@property(retain, nonatomic) NSArray *submodules; // @synthesize submodules=_submodules;
- (void)didFinish;
- (id)submodulesFromStatusOutput:(id)arg1;
- (id)arguments;
- (void)dealloc;

@end

