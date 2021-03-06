//
//  GCDTask.h
//
//  Author: Darvell Long
//  Copyright (c) 2014 Reliablehosting.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef GCDTASK_DEBUG
#define GCDDebug(str, ...) NSLog(str, ##__VA_ARGS__)
#else
#define GCDDebug(str, ...)
#endif


@interface GCDTask : NSObject
{
    NSPipe* stdoutPipe;
    NSPipe* stderrPipe;
    NSPipe* stdinPipe;
    NSTask* executingTask;
    id stdoutObserver;
    id stderrObserver;
}

@property (strong) NSString* workPath;
@property (strong) NSString* launchPath;
@property (strong) NSArray* arguments;
@property BOOL hasExecuted;
@property __block dispatch_source_t stdoutSource;
@property __block dispatch_source_t stderrSource;



- (void) launchWithOutputBlock: (void (^)(NSData* stdOutData)) stdOut
                andErrorBlock: (void (^)(NSData* stdErrData)) stdErr
                     onLaunch: (void (^)()) launched
                       onExit: (void (^)()) exit;

- (BOOL) WriteStringToStandardInput: (NSString*) input;
- (BOOL) WriteDataToStandardInput: (NSData*) input;
- (void) AddArgument: (NSString*) argument;
- (void) RequestTermination;

@end