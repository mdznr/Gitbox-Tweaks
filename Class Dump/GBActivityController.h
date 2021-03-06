//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSWindowController.h>

#import "NSTableViewDelegate-Protocol.h"
#import "NSWindowDelegate-Protocol.h"

@class NSArrayController, NSMutableArray, NSTableView, NSTextView;

__attribute__((visibility("hidden")))
@interface GBActivityController : NSWindowController <NSTableViewDelegate, NSWindowDelegate>
{
    NSMutableArray *activities;
    NSTextView *outputTextView;
    NSTableView *tableView;
    NSArrayController *arrayController;
}

+ (id)sharedActivityController;
@property(retain, nonatomic) NSArrayController *arrayController; // @synthesize arrayController;
@property(retain, nonatomic) NSTableView *tableView; // @synthesize tableView;
@property(retain, nonatomic) NSTextView *outputTextView; // @synthesize outputTextView;
@property(retain, nonatomic) NSMutableArray *activities; // @synthesize activities;
- (void)taskDidDeallocate:(id)arg1;
- (void)taskDidLaunch:(id)arg1;
- (void)taskDidTerminate:(id)arg1;
- (void)taskDidUpdate:(id)arg1;
- (id)activityForTask:(id)arg1;
- (void)tableViewSelectionDidChange:(id)arg1;
- (void)windowDidResignKey:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)windowDidLoad;
- (void)clearAll:(id)arg1;
- (void)addActivity:(id)arg1;
- (void)syncActivityOutput;
- (id)initWithWindowNibName:(id)arg1;
- (void)dealloc;

@end

