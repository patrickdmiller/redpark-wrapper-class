//
//  redparkWrapper.m
//  redpark_lib_test
//
//  Created by Patrick Miller on 4/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "redparkWrapper.h"

@implementation redparkWrapper

@synthesize rscMgr, delegate, serialCommand;

-(id) init{
    self = [super init];
    rscMgr = [[RscMgr alloc] init];
    [rscMgr setDelegate:self];
    self.serialCommand = [[NSMutableString alloc] initWithString:@""];
    return self;
}

-(void) processCommand{
    NSString *ss = [[NSString alloc] initWithString:[self.serialCommand stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]]];
    [self.serialCommand setString: @""];
    [[self delegate] newMessageAvailable:ss];
    
}

-(void) sendSerial:(NSString *)cmd {
    const char *c = [cmd UTF8String];
    for(int i=0; i< cmd.length ; i++){
        txBuffer[i]=c[i];
    }
    txBuffer[cmd.length] = '\n';
    [rscMgr write:txBuffer Length:(cmd.length+1)];
}

/* REDPARK DELEGATE METHODS *****************/

#pragma mark - RscMgrDelegate methods

- (void) cableConnected:(NSString *)protocol {
    [rscMgr setBaud:9600];
	[rscMgr open]; 
}

- (void) cableDisconnected {
    
}

- (void) portStatusChanged {
    
}

// bytes are available to be read (user calls read:)
- (void) readBytesAvailable:(UInt32)length{
    
    UInt8 newBuffer[BUFFER_LEN];
    //newBuffer is pointer and gets populated by rscMgr
    int bytesRead = [rscMgr read:newBuffer Length:length];
    NSString *newCommand = [[NSString alloc] initWithBytes:(char*)newBuffer length:length encoding:NSASCIIStringEncoding];
    [self.serialCommand appendString:newCommand];
    
    if([self.serialCommand hasSuffix:@"\n"]){
        [self processCommand];
    }
    
}

- (BOOL) rscMessageReceived:(UInt8 *)msg TotalLength:(int)len {
    return FALSE;    
}

- (void) didReceivePortConfig {
}



@end
