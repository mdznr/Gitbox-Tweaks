//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

__attribute__((visibility("hidden")))
@interface OABlockGroup : NSObject
{
    CDUnknownBlockType block;
    BOOL isWrapped;
    int counter;
}

+ (void)groupBlock:(CDUnknownBlockType)arg1 continuation:(CDUnknownBlockType)arg2;
@property(nonatomic) int counter; // @synthesize counter;
@property(nonatomic) BOOL isWrapped; // @synthesize isWrapped;
@property(copy, nonatomic) CDUnknownBlockType block; // @synthesize block;
- (void)leave;
- (void)enter;
- (void)dealloc;

@end

