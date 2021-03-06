//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBRepositorySettingsViewController.h"

@class NSArrayController, NSButton, NSMutableArray;

__attribute__((visibility("hidden")))
@interface GBRepositoryBranchesAndTagsController : GBRepositorySettingsViewController
{
    NSMutableArray *branchesBinding;
    NSMutableArray *tagsBinding;
    NSMutableArray *remoteBranchesBinding;
    NSArrayController *branchesController;
    NSArrayController *tagsController;
    NSArrayController *remoteBranchesController;
    NSButton *deleteBranchButton;
    NSButton *deleteTagButton;
    NSButton *deleteRemoteBranchButton;
    NSMutableArray *branchesToDelete;
    NSMutableArray *tagsToDelete;
    NSMutableArray *remoteBranchesToDelete;
}

@property(retain, nonatomic) NSMutableArray *remoteBranchesToDelete; // @synthesize remoteBranchesToDelete;
@property(retain, nonatomic) NSMutableArray *tagsToDelete; // @synthesize tagsToDelete;
@property(retain, nonatomic) NSMutableArray *branchesToDelete; // @synthesize branchesToDelete;
@property(retain, nonatomic) NSButton *deleteRemoteBranchButton; // @synthesize deleteRemoteBranchButton;
@property(retain, nonatomic) NSButton *deleteTagButton; // @synthesize deleteTagButton;
@property(retain, nonatomic) NSButton *deleteBranchButton; // @synthesize deleteBranchButton;
@property(retain, nonatomic) NSArrayController *remoteBranchesController; // @synthesize remoteBranchesController;
@property(retain, nonatomic) NSArrayController *tagsController; // @synthesize tagsController;
@property(retain, nonatomic) NSArrayController *branchesController; // @synthesize branchesController;
@property(retain, nonatomic) NSMutableArray *remoteBranchesBinding; // @synthesize remoteBranchesBinding;
@property(retain, nonatomic) NSMutableArray *tagsBinding; // @synthesize tagsBinding;
@property(retain, nonatomic) NSMutableArray *branchesBinding; // @synthesize branchesBinding;
- (void)tableViewSelectionDidChange:(id)arg1;
- (void)deleteRemoteBranch:(id)arg1;
- (void)deleteTag:(id)arg1;
- (void)deleteBranch:(id)arg1;
- (void)viewDidLoad;
- (void)save;
- (void)cancel;
- (void)updateButtonTitles;
- (id)title;
- (id)initWithRepository:(id)arg1;
- (void)dealloc;

@end

