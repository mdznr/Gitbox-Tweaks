//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBTask.h"

@class NSDate, NSString;

__attribute__((visibility("hidden")))
@interface GBTaskWithProgress : GBTask
{
    CDUnknownBlockType progressUpdateBlock;
    NSString *status;
    double progress;
    double extendedProgress;
    NSDate *indeterminateActivityStartDate;
    double sendingRatio;
}

+ (double)progressForDataChunk:(id)arg1 statusRef:(id *)arg2 sendingRatio:(double)arg3;
+ (double)progressWithPrefix:(id)arg1 line:(id)arg2;
@property double sendingRatio; // @synthesize sendingRatio;
@property(retain, nonatomic) NSDate *indeterminateActivityStartDate; // @synthesize indeterminateActivityStartDate;
@property double extendedProgress; // @synthesize extendedProgress;
@property double progress; // @synthesize progress;
@property(copy) NSString *status; // @synthesize status;
@property(copy, nonatomic) CDUnknownBlockType progressUpdateBlock; // @synthesize progressUpdateBlock;
- (void)didFinishInBackground;
- (void)didReceiveStandardErrorData:(id)arg1;
- (void)callProgressBlock;
- (BOOL)isRealTime;
- (id)init;
- (void)dealloc;

@end

