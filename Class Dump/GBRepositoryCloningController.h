//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSResponder.h>

#import "GBMainWindowItem-Protocol.h"
#import "GBSidebarItemObject-Protocol.h"

@class GBCloneTask, GBRepositoryCloningViewController, GBSidebarItem, NSError, NSString, NSURL;

__attribute__((visibility("hidden")))
@interface GBRepositoryCloningController : NSResponder <GBMainWindowItem, GBSidebarItemObject>
{
    GBSidebarItem *sidebarItem;
    GBRepositoryCloningViewController *viewController;
    NSString *sourceURLString;
    NSURL *targetURL;
    GBCloneTask *task;
    NSError *error;
    long long isDisabled;
    long long isSpinning;
    double sidebarItemProgress;
    NSString *progressStatus;
}

@property(copy, nonatomic) NSString *progressStatus; // @synthesize progressStatus;
@property(nonatomic) double sidebarItemProgress; // @synthesize sidebarItemProgress;
@property(nonatomic) long long isSpinning; // @synthesize isSpinning;
@property(nonatomic) long long isDisabled; // @synthesize isDisabled;
@property(retain, nonatomic) NSError *error; // @synthesize error;
@property(retain, nonatomic) GBCloneTask *task; // @synthesize task;
@property(retain, nonatomic) NSURL *targetURL; // @synthesize targetURL;
@property(retain, nonatomic) NSString *sourceURLString; // @synthesize sourceURLString;
@property(retain, nonatomic) GBRepositoryCloningViewController *viewController; // @synthesize viewController;
@property(retain, nonatomic) GBSidebarItem *sidebarItem; // @synthesize sidebarItem;
- (id)pasteboardPropertyListForType:(id)arg1;
- (id)writableTypesForPasteboard:(id)arg1;
- (BOOL)sidebarItemIsSpinning;
- (void)sidebarItemLoadContentsFromPropertyList:(id)arg1;
- (id)sidebarItemContentsPropertyList;
- (id)sidebarItemTooltip;
- (id)sidebarItemTitle;
- (void)didSelectWindowItem;
- (id)windowRepresentedURL;
- (id)windowTitle;
- (void)cancelCloning;
- (void)startCloning;
- (id)url;
- (id)init;
- (void)dealloc;

@end

