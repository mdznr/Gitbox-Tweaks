//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBRepositorySettingsViewController.h"

@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface GBRepositoryRemotesController : GBRepositorySettingsViewController
{
    NSMutableArray *remotesDictionaries;
}

@property(retain, nonatomic) NSMutableArray *remotesDictionaries; // @synthesize remotesDictionaries;
- (void)syncRemotesDictionariesWithRepository;
- (id)remotesDictionariesForRepository:(id)arg1;
- (void)viewDidLoad;
- (void)save;
- (void)cancel;
- (id)title;
- (id)initWithRepository:(id)arg1;
- (void)dealloc;

@end

