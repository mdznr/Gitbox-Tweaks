//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class GBMainWindowController, GBRootController, MASPreferencesWindowController, NSMenuItem, NSMutableArray, NSTextView;

__attribute__((visibility("hidden")))
@interface GBAppDelegate : NSObject <NSOpenSavePanelDelegate, NSApplicationDelegate>
{
    unsigned long long diffToolsControllerIndex;
    unsigned long long licenseControllerIndex;
    NSTextView *licenseTextView;
    GBRootController *rootController;
    GBMainWindowController *windowController;
    MASPreferencesWindowController *preferencesController;
    NSMutableArray *URLsToOpenAfterLaunch;
    NSMenuItem *licenseMenuItem;
    NSMenuItem *checkForUpdatesMenuItem;
    NSMenuItem *welcomeMenuItem;
    NSMenuItem *rateInAppStoreMenuItem;
}

+ (id)instance;
+ (void)initialize;
@property(retain, nonatomic) NSMenuItem *rateInAppStoreMenuItem; // @synthesize rateInAppStoreMenuItem;
@property(retain, nonatomic) NSMenuItem *welcomeMenuItem; // @synthesize welcomeMenuItem;
@property(retain, nonatomic) NSMenuItem *checkForUpdatesMenuItem; // @synthesize checkForUpdatesMenuItem;
@property(retain, nonatomic) NSMenuItem *licenseMenuItem; // @synthesize licenseMenuItem;
@property(retain, nonatomic) NSMutableArray *URLsToOpenAfterLaunch; // @synthesize URLsToOpenAfterLaunch;
@property(retain, nonatomic) MASPreferencesWindowController *preferencesController; // @synthesize preferencesController;
@property(retain, nonatomic) GBMainWindowController *windowController; // @synthesize windowController;
@property(retain, nonatomic) GBRootController *rootController; // @synthesize rootController;
@property(retain, nonatomic) NSTextView *licenseTextView; // @synthesize licenseTextView;
- (void)testUTF8Healing;
- (void)testGBAsyncUpdater;
- (void)testGBAsyncUpdaterUpdate:(id)arg1;
- (void)simulateSetNeedsUpdate:(id)arg1;
- (void)handleUrl:(id)arg1 withReplyEvent:(id)arg2;
- (void)saveItems;
- (void)rootControllerDidChangeSelection:(id)arg1;
- (void)rootControllerDidChangeContents:(id)arg1;
- (void)presentedErrorAlertDidEnd:(id)arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (id)application:(id)arg1 willPresentError:(id)arg2;
- (BOOL)applicationShouldOpenUntitledFile:(id)arg1;
- (void)applicationDidBecomeActive:(id)arg1;
- (BOOL)application:(id)arg1 openFile:(id)arg2;
- (void)applicationWillTerminate:(id)arg1;
- (void)applicationDidFinishLaunching:(id)arg1;
- (void)updateAppleEvents;
- (void)showActivityWindow:(id)arg1;
- (void)releaseNotes:(id)arg1;
- (void)showDiffToolPreferences:(id)arg1;
- (void)showLicense:(id)arg1;
- (void)showOnlineHelp:(id)arg1;
- (void)checkForUpdates:(id)arg1;
- (void)showPreferences:(id)arg1;
- (void)showMainWindow:(id)arg1;
- (void)rateInAppStore:(id)arg1;
- (void)dealloc;

@end

