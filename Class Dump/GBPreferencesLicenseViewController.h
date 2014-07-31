//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSViewController.h>

#import "MASPreferencesViewController-Protocol.h"

@class NSButton, NSImage, NSString, NSTextField;

__attribute__((visibility("hidden")))
@interface GBPreferencesLicenseViewController : NSViewController <MASPreferencesViewController>
{
    BOOL wasValid;
    BOOL didEdit;
    NSTextField *descriptionLabel;
    NSTextField *licenseField;
    NSTextField *statusLabel;
    NSButton *okButton;
}

+ (id)controller;
@property NSButton *okButton; // @synthesize okButton;
@property NSTextField *statusLabel; // @synthesize statusLabel;
@property NSTextField *licenseField; // @synthesize licenseField;
@property NSTextField *descriptionLabel; // @synthesize descriptionLabel;
@property(readonly, nonatomic) NSString *toolbarItemLabel;
@property(readonly, nonatomic) NSImage *toolbarItemImage;
@property(readonly, nonatomic) NSString *identifier;
- (void)viewDidDisappear;
- (void)viewWillAppear;
- (void)loadView;
- (void)textDidChange:(id)arg1;
- (void)website:(id)arg1;
- (void)buyFromAppStore:(id)arg1;
- (void)buy:(id)arg1;
- (void)update;
- (void)dealloc;

@end

