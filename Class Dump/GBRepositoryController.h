//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSResponder.h>

#import "GBMainWindowItem-Protocol.h"
#import "GBSidebarItemObject-Protocol.h"

@class GBAsyncUpdater, GBCommit, GBFolderMonitor, GBRepository, GBRepositoryToolbarController, GBRepositoryViewController, GBSearch, GBSidebarItem, NSArray, NSString, NSURL, NSUndoManager, OABlockTable, OAFSEventStream;

__attribute__((visibility("hidden")))
@interface GBRepositoryController : NSResponder <GBMainWindowItem, GBSidebarItemObject>
{
    BOOL started;
    BOOL stopped;
    BOOL selected;
    long long stagingCounter;
    double lastFSEventUpdateTimestamp;
    double repeatedUpdateDelay;
    int remoteStateUpdateGeneration;
    double nextRemoteStateUpdateTimestamp;
    double prevRemoteStateUpdateTimestamp;
    double remoteStateUpdateInterval;
    BOOL authenticationInProgress;
    BOOL wantsAutoResetSubmodules;
    BOOL stageHasCleanSubmodules;
    BOOL initialUpdateDone;
    int laterStageUpdateScheduleCounter;
    GBRepository *repository;
    GBSidebarItem *sidebarItem;
    NSString *_userDefinedName;
    GBRepositoryToolbarController *toolbarController;
    GBRepositoryViewController *viewController;
    GBCommit *selectedCommit;
    NSString *lastCommitBranchName;
    OABlockTable *blockTable;
    GBFolderMonitor *folderMonitor;
    long long isRemoteBranchesDisabled;
    BOOL isCommitting;
    BOOL isDisappearedFromFileSystem;
    long long isDisabled;
    long long isSpinning;
    unsigned long long commitsBadgeInteger;
    unsigned long long stageBadgeInteger;
    NSString *searchString;
    NSArray *searchResults;
    GBSearch *currentSearch;
    double searchProgress;
    NSUndoManager *undoManager;
    NSArray *_submoduleControllers;
    NSArray *_submodules;
    CDUnknownBlockType _localStateUpdatePendingBlock;
    CDUnknownBlockType _pendingContinuationToBeginAuthSession;
    GBAsyncUpdater *stageUpdater;
    GBAsyncUpdater *submodulesUpdater;
    GBAsyncUpdater *localRefsUpdater;
    GBAsyncUpdater *commitsUpdater;
    GBAsyncUpdater *remoteRefsUpdater;
    GBAsyncUpdater *fetchUpdater;
}

+ (id)repositoryControllerWithURL:(id)arg1;
@property(retain, nonatomic) GBAsyncUpdater *fetchUpdater; // @synthesize fetchUpdater;
@property(retain, nonatomic) GBAsyncUpdater *remoteRefsUpdater; // @synthesize remoteRefsUpdater;
@property(retain, nonatomic) GBAsyncUpdater *commitsUpdater; // @synthesize commitsUpdater;
@property(retain, nonatomic) GBAsyncUpdater *localRefsUpdater; // @synthesize localRefsUpdater;
@property(retain, nonatomic) GBAsyncUpdater *submodulesUpdater; // @synthesize submodulesUpdater;
@property(retain, nonatomic) GBAsyncUpdater *stageUpdater; // @synthesize stageUpdater;
@property(copy, nonatomic) CDUnknownBlockType pendingContinuationToBeginAuthSession; // @synthesize pendingContinuationToBeginAuthSession=_pendingContinuationToBeginAuthSession;
@property(copy, nonatomic) CDUnknownBlockType localStateUpdatePendingBlock; // @synthesize localStateUpdatePendingBlock=_localStateUpdatePendingBlock;
@property(retain, nonatomic) NSArray *submodules; // @synthesize submodules=_submodules;
@property(retain, nonatomic) NSArray *submoduleControllers; // @synthesize submoduleControllers=_submoduleControllers;
@property(retain, nonatomic) NSUndoManager *undoManager; // @synthesize undoManager;
@property(nonatomic) double searchProgress; // @synthesize searchProgress;
@property(retain, nonatomic) GBSearch *currentSearch; // @synthesize currentSearch;
@property(retain, nonatomic) NSArray *searchResults; // @synthesize searchResults;
@property(copy, nonatomic) NSString *searchString; // @synthesize searchString;
@property(nonatomic) unsigned long long stageBadgeInteger; // @synthesize stageBadgeInteger;
@property(nonatomic) unsigned long long commitsBadgeInteger; // @synthesize commitsBadgeInteger;
@property(nonatomic) long long isSpinning; // @synthesize isSpinning;
@property(nonatomic) long long isDisabled; // @synthesize isDisabled;
@property(nonatomic) BOOL isDisappearedFromFileSystem; // @synthesize isDisappearedFromFileSystem;
@property(nonatomic) BOOL isCommitting; // @synthesize isCommitting;
@property(nonatomic) long long isRemoteBranchesDisabled; // @synthesize isRemoteBranchesDisabled;
@property(retain, nonatomic) GBFolderMonitor *folderMonitor; // @synthesize folderMonitor;
@property(retain, nonatomic) OABlockTable *blockTable; // @synthesize blockTable;
@property(copy, nonatomic) NSString *lastCommitBranchName; // @synthesize lastCommitBranchName;
@property(retain, nonatomic) GBCommit *selectedCommit; // @synthesize selectedCommit;
@property(retain, nonatomic) GBRepositoryViewController *viewController; // @synthesize viewController;
@property(retain, nonatomic) GBRepositoryToolbarController *toolbarController; // @synthesize toolbarController;
@property(copy, nonatomic) NSString *userDefinedName; // @synthesize userDefinedName=_userDefinedName;
@property(retain, nonatomic) GBSidebarItem *sidebarItem; // @synthesize sidebarItem;
@property(retain, nonatomic) GBRepository *repository; // @synthesize repository;
- (id)pasteboardPropertyListForType:(id)arg1;
- (id)writableTypesForPasteboard:(id)arg1;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)removePathsFromStage:(id)arg1 block:(CDUnknownBlockType)arg2;
- (BOOL)validateRevertCommit:(id)arg1;
- (void)revertCommit:(id)arg1;
- (BOOL)validateResetBranchToCommit:(id)arg1;
- (void)resetBranchToCommit:(id)arg1;
- (BOOL)validateApplyAsPatchCommit:(id)arg1;
- (void)applyAsPatchCommit:(id)arg1;
- (BOOL)validateCherryPickCommit:(id)arg1;
- (void)cherryPickCommit:(id)arg1;
- (BOOL)validateMergeCommit:(id)arg1;
- (void)mergeCommit:(id)arg1;
- (BOOL)validateResetChanges:(id)arg1;
- (void)resetSubmodule:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)resetChanges:(id)arg1;
- (void)removeOldStashes:(id)arg1;
- (void)removeAllStashes:(id)arg1;
- (BOOL)validateApplyStashMenu:(id)arg1;
- (void)applyStashMenu:(id)arg1;
- (void)applyStash:(id)arg1;
- (BOOL)validateStashChanges:(id)arg1;
- (void)stashChanges:(id)arg1;
- (BOOL)validateOpenInXcode:(id)arg1;
- (void)openOneProjectInXcode:(id)arg1;
- (void)openInXcode:(id)arg1;
- (void)editRemotes:(id)arg1;
- (void)editBranchesAndTags:(id)arg1;
- (void)openSettings:(id)arg1;
- (BOOL)validatePush:(id)arg1;
- (BOOL)validatePull:(id)arg1;
- (BOOL)validateFetch:(id)arg1;
- (void)previousCommit:(id)arg1;
- (void)nextCommit:(id)arg1;
- (void)rebaseContinue:(id)arg1;
- (void)rebaseSkip:(id)arg1;
- (void)rebaseCancel:(id)arg1;
- (void)rebase:(id)arg1;
- (void)forcePush:(id)arg1;
- (void)push:(id)arg1;
- (void)undoPushWithForce:(BOOL)arg1 commitId:(id)arg2;
- (void)pushWithForce:(BOOL)arg1;
- (void)helperPushBranch:(id)arg1 toRemoteBranch:(id)arg2 forced:(BOOL)arg3;
- (void)undoPullOverCommitId:(id)arg1 title:(id)arg2;
- (void)pull:(id)arg1;
- (void)fetch:(id)arg1;
- (void)fetchRemote:(id)arg1 silently:(BOOL)arg2 withBlock:(CDUnknownBlockType)arg3;
- (void)undoCommitWithMessage:(id)arg1 commitId:(id)arg2 undo:(BOOL)arg3;
- (void)commitWithMessage:(id)arg1;
- (void)deleteFilesInChanges:(id)arg1;
- (void)revertChanges:(id)arg1;
- (void)unstageChanges:(id)arg1;
- (void)stageChanges:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)stageChanges:(id)arg1;
- (void)stagingHelperForChanges:(id)arg1 withBlock:(CDUnknownBlockType)arg2 postStageBlock:(CDUnknownBlockType)arg3;
- (void)selectCommitId:(id)arg1;
- (void)createAndSelectRemoteBranchWithName:(id)arg1 remote:(id)arg2;
- (void)selectRemoteBranch:(id)arg1;
- (BOOL)validateDeleteTagMenu:(id)arg1;
- (void)deleteTagMenu:(id)arg1;
- (BOOL)validateDeleteTag:(id)arg1;
- (void)deleteTag:(id)arg1;
- (BOOL)validateNewTag:(id)arg1;
- (void)newTag:(id)arg1;
- (void)removeRefs:(id)arg1;
- (void)deleteTagWithName:(id)arg1 commitId:(id)arg2;
- (void)createTagWithName:(id)arg1 commitId:(id)arg2;
- (void)checkoutNewBranchWithName:(id)arg1 commit:(id)arg2;
- (void)checkoutRef:(id)arg1 withNewName:(id)arg2;
- (void)checkoutRef:(id)arg1;
- (void)checkoutHelper:(CDUnknownBlockType)arg1;
- (void)openInTerminal:(id)arg1;
- (void)openInFinder:(id)arg1;
- (void)redo:(id)arg1;
- (void)undo:(id)arg1;
- (void)cancelSearch:(id)arg1;
- (void)search:(id)arg1;
- (void)performFindPanelAction:(id)arg1;
- (void)searchDidUpdate:(id)arg1;
@property(readonly, nonatomic, getter=isSearching) BOOL searching;
- (void)endAuthenticatedSession:(CDUnknownBlockType)arg1;
- (void)beginAuthenticatedSession:(CDUnknownBlockType)arg1;
- (void)popSpinning;
- (void)pushSpinning;
- (void)popRemoteBranchesDisabled;
- (void)pushRemoteBranchesDisabled;
- (void)popDisabled;
- (void)pushDisabled;
- (void)submoduleCloningControllerDidFinish:(id)arg1;
- (void)repositoryControllerDidUpdateBranch:(id)arg1;
- (void)repositoryControllerDidUpdateStageWithNewChanges:(id)arg1;
- (void)optimizeRepository:(id)arg1;
- (void)stageDidUpdateChanges:(id)arg1;
- (void)repositoryDidUpdateProgress:(id)arg1;
- (void)updateBranchesForRemote:(id)arg1 silently:(BOOL)arg2 withBlock:(CDUnknownBlockType)arg3;
- (void)updateRemoteRefsSilently:(BOOL)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)updateRemoteRefsWithBlock:(CDUnknownBlockType)arg1;
- (void)updateRemoteStateAfterDelay:(double)arg1;
- (void)invalidateDelayedRemoteStateUpdate;
- (void)folderMonitorDidUpdate:(id)arg1;
- (void)shouldUpdateFetch:(id)arg1;
- (void)shouldUpdateRemoteRefs:(id)arg1;
- (void)shouldUpdateCommits:(id)arg1;
- (void)updateCommitsBadgeInteger;
- (void)shouldUpdateLocalRefs:(id)arg1;
- (void)shouldUpdateSubmodules:(id)arg1;
- (BOOL)submodulesOutOfSync;
- (void)shouldUpdateStage:(id)arg1;
- (BOOL)stageHasCleanSubmodules;
- (void)setNeedsUpdateFetch;
- (void)setNeedsUpdateRemoteRefs;
- (void)setNeedsUpdateCommits;
- (void)setNeedsUpdateLocalRefs;
- (void)setNeedsUpdateSubmodules;
- (void)setNeedsUpdateStage;
- (void)initialUpdate;
- (void)setNeedsUpdateLocalState;
- (void)stop;
- (void)start;
- (void)sidebarItemLoadContentsFromPropertyList:(id)arg1;
- (id)sidebarItemContentsPropertyList;
- (id)sidebarItemImage;
- (BOOL)sidebarItemIsSpinning;
- (unsigned long long)sidebarItemBadgeInteger;
- (BOOL)sidebarItemIsExpandable;
- (id)sidebarItemTooltip;
- (void)sidebarItemSetStringValue:(id)arg1;
- (id)sidebarItemTitle;
- (id)sidebarItemChildAtIndex:(long long)arg1;
- (long long)sidebarItemNumberOfChildren;
- (id)sidebarItemMenu;
- (void)addOpenMenuItemsToMenu:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)didSelectWindowItem;
- (void)willDeselectWindowItem;
- (id)windowRepresentedURL;
- (id)windowTitle;
- (BOOL)checkRepositoryExistance;
- (id)stageAndCommits;
- (id)contextCommit;
- (id)visibleCommits;
- (id)icon;
@property(readonly, nonatomic) NSURL *url;
@property(retain, nonatomic) OAFSEventStream *fsEventStream; // @dynamic fsEventStream;
- (id)description;
- (id)initWithURL:(id)arg1;
- (void)dealloc;

@end

