//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSAlert.h>

@interface NSAlert (OAAlertHelpers)
+ (BOOL)prompt:(id)arg1 description:(id)arg2;
+ (BOOL)prompt:(id)arg1 description:(id)arg2 window:(id)arg3;
+ (BOOL)prompt:(id)arg1 description:(id)arg2 ok:(id)arg3;
+ (void)alertDidEnd:(id)arg1 returnCode:(long long)arg2 contextInfo:(long long *)arg3;
+ (BOOL)prompt:(id)arg1 description:(id)arg2 ok:(id)arg3 window:(id)arg4;
+ (long long)message:(id)arg1 description:(id)arg2 buttonTitle:(id)arg3;
+ (long long)message:(id)arg1 description:(id)arg2;
+ (long long)message:(id)arg1;
+ (long long)error:(id)arg1;
@end

