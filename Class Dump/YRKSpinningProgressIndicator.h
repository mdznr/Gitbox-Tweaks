//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSView.h>

@class NSColor, NSThread, NSTimer;

__attribute__((visibility("hidden")))
@interface YRKSpinningProgressIndicator : NSView
{
    int _position;
    int _numFins;
    double _animationAngel;
    id _finColors;
    BOOL _isAnimating;
    BOOL _isFadingOut;
    NSTimer *_animationTimer;
    NSThread *_animationThread;
    NSColor *_foreColor;
    NSColor *_backColor;
    BOOL _drawsBackground;
    BOOL _usesThreadedAnimation;
    BOOL _isIndeterminate;
    double _currentValue;
    double _maxValue;
    BOOL _actsAsCell;
}

@property(nonatomic) BOOL actsAsCell; // @synthesize actsAsCell=_actsAsCell;
@property(nonatomic) double maxValue; // @synthesize maxValue=_maxValue;
@property(nonatomic) double doubleValue; // @synthesize doubleValue=_currentValue;
@property(nonatomic, getter=isIndeterminate) BOOL indeterminate; // @synthesize indeterminate=_isIndeterminate;
@property(nonatomic) BOOL usesThreadedAnimation; // @synthesize usesThreadedAnimation=_usesThreadedAnimation;
@property(nonatomic) BOOL drawsBackground; // @synthesize drawsBackground=_drawsBackground;
@property(retain, nonatomic) NSColor *backgroundColor; // @synthesize backgroundColor=_backColor;
@property(retain, nonatomic) NSColor *color; // @synthesize color=_foreColor;
- (void)animateInBackgroundThread;
- (void)generateFinColorsStartAtPosition:(int)arg1;
- (void)actuallyStopAnimation;
- (void)actuallyStartAnimation;
- (void)updateFrame:(id)arg1;
- (void)setStyle:(unsigned long long)arg1;
- (void)stopAnimation:(id)arg1;
- (void)startAnimation:(id)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (void)setNeedsDisplay:(BOOL)arg1;
- (void)viewDidMoveToWindow;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

