//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import "GBTask.h"

@class NSString, NSURL;

__attribute__((visibility("hidden")))
@interface GBExtractFileTask : GBTask
{
    NSString *objectId;
    NSString *commitId;
    NSString *folder;
    NSURL *originalURL;
    NSURL *targetURL;
}

@property(retain, nonatomic) NSURL *targetURL; // @synthesize targetURL;
@property(retain, nonatomic) NSURL *originalURL; // @synthesize originalURL;
@property(copy, nonatomic) NSString *folder; // @synthesize folder;
@property(copy, nonatomic) NSString *commitId; // @synthesize commitId;
@property(copy, nonatomic) NSString *objectId; // @synthesize objectId;
- (id)arguments;
- (void)willPrepareTask;
- (id)prettyFileName;
- (void)dealloc;

@end

