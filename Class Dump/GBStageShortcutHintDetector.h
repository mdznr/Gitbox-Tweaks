//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSView;

__attribute__((visibility("hidden")))
@interface GBStageShortcutHintDetector : NSObject
{
    NSView *view;
    BOOL addedNewLine;
    BOOL removedNewLine;
    BOOL finishedPlayingWithTooltip;
}

+ (id)detectorWithView:(id)arg1;
@property(nonatomic) BOOL finishedPlayingWithTooltip; // @synthesize finishedPlayingWithTooltip;
@property(nonatomic) BOOL removedNewLine; // @synthesize removedNewLine;
@property(nonatomic) BOOL addedNewLine; // @synthesize addedNewLine;
@property(retain, nonatomic) NSView *view; // @synthesize view;
- (void)reset;
- (void)showView;
- (void)textView:(id)arg1 didChangeTextInRange:(struct _NSRange)arg2 replacementString:(id)arg3;
- (void)dealloc;

@end

