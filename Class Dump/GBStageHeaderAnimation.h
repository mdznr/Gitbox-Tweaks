//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSAnimation.h>

@class GBStageViewController, NSString;

__attribute__((visibility("hidden")))
@interface GBStageHeaderAnimation : NSAnimation
{
    NSString *message;
    GBStageViewController *controller;
    struct CGRect headerFrame;
    struct CGRect headerFrameInitial;
    struct CGRect textScrollViewFrame;
    struct CGRect textScrollViewFrameInitial;
    double buttonAlpha;
    double buttonAlphaInitial;
    double topPadding;
    double topPaddingInitial;
    struct CGRect tableViewFrame;
    struct CGRect tableViewFrameInitial;
}

+ (id)animationWithController:(id)arg1;
@property(nonatomic) struct CGRect tableViewFrameInitial; // @synthesize tableViewFrameInitial;
@property(nonatomic) struct CGRect tableViewFrame; // @synthesize tableViewFrame;
@property(nonatomic) double topPaddingInitial; // @synthesize topPaddingInitial;
@property(nonatomic) double topPadding; // @synthesize topPadding;
@property(nonatomic) double buttonAlphaInitial; // @synthesize buttonAlphaInitial;
@property(nonatomic) double buttonAlpha; // @synthesize buttonAlpha;
@property(nonatomic) struct CGRect textScrollViewFrameInitial; // @synthesize textScrollViewFrameInitial;
@property(nonatomic) struct CGRect textScrollViewFrame; // @synthesize textScrollViewFrame;
@property(nonatomic) struct CGRect headerFrameInitial; // @synthesize headerFrameInitial;
@property(nonatomic) struct CGRect headerFrame; // @synthesize headerFrame;
@property(nonatomic) GBStageViewController *controller; // @synthesize controller;
@property(copy, nonatomic) NSString *message; // @synthesize message;
- (void)stopAnimation;
- (void)startAnimation;
- (void)prepareAnimation;
- (void)setCurrentProgress:(float)arg1;
- (id)runLoopModesForAnimating;
- (void)dealloc;

@end

