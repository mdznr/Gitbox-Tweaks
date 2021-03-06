//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBWindowControllerWithCallback.h"

#import "NSWindowDelegate-Protocol.h"

@class NSArray, NSString, NSTextView, NSURL;

__attribute__((visibility("hidden")))
@interface GBFileEditingController : GBWindowControllerWithCallback <NSWindowDelegate>
{
    BOOL contentPrepared;
    NSURL *URL;
    NSString *title;
    NSArray *linesToAppend;
    NSTextView *textView;
}

+ (id)controller;
@property(retain, nonatomic) NSTextView *textView; // @synthesize textView;
@property(retain, nonatomic) NSArray *linesToAppend; // @synthesize linesToAppend;
@property(retain, nonatomic) NSString *title; // @synthesize title;
@property(retain, nonatomic) NSURL *URL; // @synthesize URL;
- (void)windowDidBecomeKey:(id)arg1;
- (void)windowDidLoad;
- (void)prepareContent;
- (void)onCancel:(id)arg1;
- (void)onOK:(id)arg1;
- (void)dealloc;

@end

