//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSApplication.h>

__attribute__((visibility("hidden")))
@interface GBApplication : NSApplication
{
    int ignoreUserAttentionRequests;
    BOOL didTerminateSafely;
}

@property(nonatomic) BOOL didTerminateSafely; // @synthesize didTerminateSafely;
- (long long)requestUserAttention:(unsigned long long)arg1;
- (void)endIgnoreUserAttentionRequests;
- (void)beginIgnoreUserAttentionRequests;

@end

