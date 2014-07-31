//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSMutableArray, NSString;

__attribute__((visibility("hidden")))
@interface OABlockQueue : NSObject
{
    NSString *name;
    NSMutableArray *queue;
    long long maxConcurrentOperationCount;
    long long operationCount;
    BOOL tooBigQueue;
}

+ (id)queueWithName:(id)arg1 concurrency:(long long)arg2;
@property(nonatomic) BOOL tooBigQueue; // @synthesize tooBigQueue;
@property(nonatomic) long long operationCount; // @synthesize operationCount;
@property(nonatomic) long long maxConcurrentOperationCount; // @synthesize maxConcurrentOperationCount;
@property(retain, nonatomic) NSMutableArray *queue; // @synthesize queue;
@property(copy, nonatomic) NSString *name; // @synthesize name;
- (void)proceed;
- (void)endBlock;
- (void)prependBlock:(CDUnknownBlockType)arg1;
- (void)addBlock:(CDUnknownBlockType)arg1;
- (id)init;
- (void)dealloc;

@end
