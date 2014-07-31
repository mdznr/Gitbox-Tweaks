//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface OAHTTPQueue : NSObject
{
    NSMutableArray *queue;
    NSMutableArray *activeDownloads;
    unsigned long long maxConcurrentOperationCount;
    BOOL coalesceURLs;
    unsigned long long limit;
    BOOL cancelling;
}

@property(nonatomic) BOOL cancelling; // @synthesize cancelling;
@property(nonatomic) unsigned long long limit; // @synthesize limit;
@property(nonatomic) BOOL coalesceURLs; // @synthesize coalesceURLs;
@property(nonatomic) unsigned long long maxConcurrentOperationCount; // @synthesize maxConcurrentOperationCount;
@property(retain, nonatomic) NSMutableArray *activeDownloads; // @synthesize activeDownloads;
@property(retain, nonatomic) NSMutableArray *queue; // @synthesize queue;
- (void)cancel;
- (void)proceed;
- (void)enumerateDownloadsUsingBlock:(CDUnknownBlockType)arg1;
- (void)removeDownload:(id)arg1;
- (void)addDownload:(id)arg1;
@property(readonly, nonatomic) unsigned long long operationCount; // @dynamic operationCount;
- (void)dealloc;
- (id)init;

@end
