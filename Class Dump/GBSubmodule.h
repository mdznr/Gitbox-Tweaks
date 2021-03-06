//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSString, NSURL;

__attribute__((visibility("hidden")))
@interface GBSubmodule : NSObject
{
    NSString *_path;
    NSURL *_parentURL;
    NSURL *_remoteURL;
    NSString *_status;
    NSString *_commitId;
    struct dispatch_queue_s *dispatchQueue;
}

@property(nonatomic) struct dispatch_queue_s *dispatchQueue; // @synthesize dispatchQueue;
@property(copy, nonatomic) NSString *commitId; // @synthesize commitId=_commitId;
@property(copy, nonatomic) NSString *status; // @synthesize status=_status;
@property(retain, nonatomic) NSURL *remoteURL; // @synthesize remoteURL=_remoteURL;
@property(retain, nonatomic) NSURL *parentURL; // @synthesize parentURL=_parentURL;
@property(copy, nonatomic) NSString *path; // @synthesize path=_path;
- (void)setPlistRepresentation:(id)arg1;
- (id)plistRepresentation;
- (id)description;
@property(readonly, nonatomic) NSURL *localURL;
- (void)dealloc;

@end

