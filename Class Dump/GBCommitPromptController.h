//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBBasePromptController.h"

@class NSMutableArray, NSString, NSTextField, NSTextView;

__attribute__((visibility("hidden")))
@interface GBCommitPromptController : GBBasePromptController
{
    unsigned long long messageHistoryIndex;
    BOOL addedNewLine;
    BOOL removedNewLine;
    BOOL finishedPlayingWithTooltip;
    NSString *value;
    NSString *branchName;
    NSMutableArray *messageHistory;
    NSTextView *textView;
    NSTextField *shortcutTipLabel;
    NSTextField *branchHintLabel;
}

@property(retain) NSTextField *branchHintLabel; // @synthesize branchHintLabel;
@property(retain) NSTextField *shortcutTipLabel; // @synthesize shortcutTipLabel;
@property(retain) NSTextView *textView; // @synthesize textView;
@property(retain) NSMutableArray *messageHistory; // @synthesize messageHistory;
@property(retain) NSString *branchName; // @synthesize branchName;
@property(retain) NSString *value; // @synthesize value;
- (void)showShortcutTip;
- (BOOL)textView:(id)arg1 shouldChangeTextInRange:(struct _NSRange)arg2 replacementString:(id)arg3;
- (void)windowDidResignKey:(id)arg1;
- (void)updateWindow;
- (void)nextMessage:(id)arg1;
- (void)previousMessage:(id)arg1;
- (void)addMessageToHistory;
- (void)rewindMessageHistory;
- (void)onCancel:(id)arg1;
- (void)onOK:(id)arg1;
- (void)resetMagicFlags;
- (void)dealloc;

@end

