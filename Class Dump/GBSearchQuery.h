//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSArray, NSString;

__attribute__((visibility("hidden")))
@interface GBSearchQuery : NSObject
{
    NSString *sourceString;
    NSArray *tokens;
}

+ (id)queryWithString:(id)arg1;
@property(retain, nonatomic) NSArray *tokens; // @synthesize tokens;
@property(copy, nonatomic) NSString *sourceString; // @synthesize sourceString;
- (id)tokensForString:(id)arg1;
- (struct _NSRange)rangeOfToken:(id)arg1 inString:(id)arg2;
- (BOOL)matchesString:(id)arg1;
- (BOOL)matchTokens:(CDUnknownBlockType)arg1;
- (id)description;
- (void)dealloc;

@end

