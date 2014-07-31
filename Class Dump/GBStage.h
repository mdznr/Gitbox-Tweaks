//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBCommit.h"

@class NSArray, NSData, NSString;

__attribute__((visibility("hidden")))
@interface GBStage : GBCommit
{
    BOOL stageTransactionInProgress;
    int stageStateCounter;
    BOOL updating;
    NSArray *stagedChanges;
    NSArray *unstagedChanges;
    NSArray *untrackedChanges;
    NSString *currentCommitMessage;
    BOOL rebaseConflict;
    NSData *previousChangesData;
}

@property(copy, nonatomic) NSData *previousChangesData; // @synthesize previousChangesData;
@property(nonatomic, getter=isRebaseConflict) BOOL rebaseConflict; // @synthesize rebaseConflict;
@property(copy, nonatomic) NSString *currentCommitMessage; // @synthesize currentCommitMessage;
@property(retain, nonatomic) NSArray *untrackedChanges; // @synthesize untrackedChanges;
@property(retain, nonatomic) NSArray *unstagedChanges; // @synthesize unstagedChanges;
@property(retain, nonatomic) NSArray *stagedChanges; // @synthesize stagedChanges;
@property(nonatomic, getter=isUpdating) BOOL updating; // @synthesize updating;
- (void)flushBlocks:(id)arg1;
- (void)arrangeChanges;
- (void)launchTaskByChunksWithArguments:(id)arg1 paths:(id)arg2 block:(CDUnknownBlockType)arg3 taskCallback:(CDUnknownBlockType)arg4 atomic:(BOOL)arg5;
- (void)endStageTransaction;
- (void)beginStageTransaction:(CDUnknownBlockType)arg1;
- (void)deleteFilesInChanges:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)revertChanges:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)stageAllWithBlock:(CDUnknownBlockType)arg1;
- (void)unstageChanges:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)stageChanges:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)stageAddedPaths:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)stageDeletedPaths:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)loadChangesWithBlock:(CDUnknownBlockType)arg1;
- (void)updateStageWithBlock:(CDUnknownBlockType)arg1;
- (void)updateConflictState;
- (unsigned long long)totalPendingChanges;
- (id)message;
- (id)asStage;
- (BOOL)isStage;
- (id)defaultStashMessage;
- (BOOL)isCommitable;
- (BOOL)isStashable;
- (BOOL)isDirty;
- (id)description;
- (id)init;
- (void)dealloc;

@end

