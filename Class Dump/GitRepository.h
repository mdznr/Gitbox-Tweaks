//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSURL;

__attribute__((visibility("hidden")))
@interface GitRepository : NSObject
{
    NSURL *URL;
    struct git_repository *repository;
}

+ (id)repositoryWithURL:(id)arg1;
@property(nonatomic) struct git_repository *repository; // @synthesize repository;
@property(retain, nonatomic) NSURL *URL; // @synthesize URL;
- (id)commitIdForRefName:(id)arg1;
- (id)config;
- (void)reloadRepository;
- (void)dealloc;
- (id)init;

@end

