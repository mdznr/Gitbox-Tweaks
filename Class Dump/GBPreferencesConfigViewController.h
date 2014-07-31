//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSViewController.h>

#import "MASPreferencesViewController-Protocol.h"

@class NSImage, NSString, NSTextField, NSTextView, NSView;

__attribute__((visibility("hidden")))
@interface GBPreferencesConfigViewController : NSViewController <MASPreferencesViewController>
{
    NSView *currentView;
    NSView *basicView;
    NSView *advancedView;
    NSTextView *configTextView;
    NSTextView *ignoreTextView;
    NSTextField *nameTextField;
    NSTextField *emailTextField;
    NSTextField *label;
    NSString *labelString;
}

+ (id)controller;
@property(copy, nonatomic) NSString *labelString; // @synthesize labelString;
@property NSTextField *label; // @synthesize label;
@property NSTextField *emailTextField; // @synthesize emailTextField;
@property NSTextField *nameTextField; // @synthesize nameTextField;
@property NSTextView *ignoreTextView; // @synthesize ignoreTextView;
@property NSTextView *configTextView; // @synthesize configTextView;
@property NSView *advancedView; // @synthesize advancedView;
@property NSView *basicView; // @synthesize basicView;
- (void)viewWillAppear;
@property(readonly, nonatomic) NSString *toolbarItemLabel;
@property(readonly, nonatomic) NSImage *toolbarItemImage;
@property(readonly, nonatomic) NSString *identifier;
- (void)loadView;
- (void)ignoreTextDidChange:(id)arg1;
- (void)configTextDidChange:(id)arg1;
- (void)nameOrEmailDidChange:(id)arg1;
- (void)toggleMode:(id)arg1;
- (void)loadData;
- (void)loadBasicData;
- (void)loadConfigData;
- (void)loadIgnoreData;
- (id)gitignoreURL;
- (id)configURL;
- (void)dealloc;

@end

