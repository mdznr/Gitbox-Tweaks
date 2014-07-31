//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSDate, NSString;

__attribute__((visibility("hidden")))
@interface GBStash : NSObject
{
    NSString *ref;
    NSDate *date;
    NSString *rawMessage;
}

+ (double)oldStashesTreshold;
@property(copy, nonatomic) NSString *rawMessage; // @synthesize rawMessage;
@property(retain, nonatomic) NSDate *date; // @synthesize date;
@property(copy, nonatomic) NSString *ref; // @synthesize ref;
@property(readonly, nonatomic) NSString *menuTitle;
@property(readonly, nonatomic) NSString *message; // @dynamic message;
- (BOOL)isOldStash;
- (void)dealloc;

@end

