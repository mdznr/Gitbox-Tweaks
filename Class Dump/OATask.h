//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "NSCopying-Protocol.h"

@class NSArray, NSData, NSDate, NSFileHandle, NSMutableData, NSMutableDictionary, NSString, NSTask, OAPseudoTTY;

__attribute__((visibility("hidden")))
@interface OATask : NSObject <NSCopying>
{
    NSString *executableName;
    NSString *launchPath;
    NSString *currentDirectoryPath;
    NSArray *arguments;
    BOOL interactive;
    BOOL realTime;
    id standardOutputHandleOrPipe;
    id standardErrorHandleOrPipe;
    NSMutableData *standardOutputData;
    NSMutableData *standardErrorData;
    struct dispatch_queue_s *dispatchQueue;
    CDUnknownBlockType didTerminateBlock;
    CDUnknownBlockType didReceiveDataBlock;
    BOOL isWaiting;
    NSMutableDictionary *additionalEnvironment;
    NSTask *nstask;
    struct dispatch_queue_s *originDispatchQueue;
    BOOL isLaunched;
    NSFileHandle *standardOutputFileHandle;
    NSFileHandle *standardErrorFileHandle;
    OAPseudoTTY *pseudoTTY;
    NSDate *launchDate;
}

+ (id)systemPathForExecutable:(id)arg1;
+ (id)pathForExecutableUsingBruteForce:(id)arg1;
+ (id)pathForExecutableUsingWhich:(id)arg1;
+ (id)task;
@property(retain, nonatomic) NSDate *launchDate; // @synthesize launchDate;
@property(retain, nonatomic) OAPseudoTTY *pseudoTTY; // @synthesize pseudoTTY;
@property(retain, nonatomic) NSFileHandle *standardErrorFileHandle; // @synthesize standardErrorFileHandle;
@property(retain, nonatomic) NSFileHandle *standardOutputFileHandle; // @synthesize standardOutputFileHandle;
@property(nonatomic) BOOL isLaunched; // @synthesize isLaunched;
@property(nonatomic) struct dispatch_queue_s *originDispatchQueue; // @synthesize originDispatchQueue;
@property(retain, nonatomic) NSTask *nstask; // @synthesize nstask;
@property(retain, nonatomic) NSMutableDictionary *additionalEnvironment; // @synthesize additionalEnvironment;
@property(nonatomic) BOOL isWaiting; // @synthesize isWaiting;
@property(copy, nonatomic) CDUnknownBlockType didReceiveDataBlock; // @synthesize didReceiveDataBlock;
@property(copy, nonatomic) CDUnknownBlockType didTerminateBlock; // @synthesize didTerminateBlock;
@property(nonatomic) struct dispatch_queue_s *dispatchQueue; // @synthesize dispatchQueue;
@property(retain, nonatomic) NSMutableData *standardErrorData; // @synthesize standardErrorData;
@property(retain, nonatomic) NSMutableData *standardOutputData; // @synthesize standardOutputData;
@property(retain, nonatomic) id standardErrorHandleOrPipe; // @synthesize standardErrorHandleOrPipe;
@property(retain, nonatomic) id standardOutputHandleOrPipe; // @synthesize standardOutputHandleOrPipe;
@property(nonatomic, getter=isRealTime) BOOL realTime; // @synthesize realTime;
@property(nonatomic, getter=isInteractive) BOOL interactive; // @synthesize interactive;
@property(retain, nonatomic) NSArray *arguments; // @synthesize arguments;
@property(copy, nonatomic) NSString *currentDirectoryPath; // @synthesize currentDirectoryPath;
@property(copy, nonatomic) NSString *launchPath; // @synthesize launchPath;
@property(copy, nonatomic) NSString *executableName; // @synthesize executableName;
- (void)fileHandleReadCompletion:(id)arg1;
- (void)nsTaskDidTerminate:(id)arg1;
- (void)readStandardOutputAndStandardError;
- (void)prepareTask;
- (void)prepareLaunchPathIfNeeded:(CDUnknownBlockType)arg1;
- (void)didFinish;
- (void)didFinishInBackground;
- (void)didReceiveStandardErrorData:(id)arg1;
- (void)didReceiveStandardOutputData:(id)arg1;
- (id)configureEnvironment:(id)arg1;
- (void)willPrepareTask;
- (void)willLaunchTask;
- (void)terminate;
- (void)writeLine:(id)arg1;
- (void)writeData:(id)arg1;
- (void)launchAndWait;
- (void)launchInteractively;
- (void)launch;
- (void)mergeEnvironment:(id)arg1;
- (void)setEnvironmentValue:(id)arg1 forKey:(id)arg2;
@property(readonly, nonatomic) int terminationStatus; // @dynamic terminationStatus;
@property(readonly, nonatomic) BOOL isRunning; // @dynamic isRunning;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;
- (void)dealloc;
- (id)description;
- (id)showErrorIfNeeded;
- (id)showError;
- (BOOL)isError;
- (id)command;
- (void)launchInQueue:(struct dispatch_queue_s *)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)launchWithBlock:(CDUnknownBlockType)arg1;
- (id)UTF8ErrorAndOutput;
- (id)UTF8Error;
- (id)UTF8OutputStripped;
- (id)UTF8Output;
@property(readonly, nonatomic) NSData *output;

@end
