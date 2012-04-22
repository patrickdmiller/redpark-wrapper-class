//
//  redparkWrapper.h
//  redpark_lib_test
//
//  Created by Patrick Miller on 4/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "RscMgr.h"


#define BUFFER_LEN 1024


@protocol RedparkWrapperDelegate <NSObject>
@required
-(void) newMessageAvailable:(NSString*)msg;
@end


@interface redparkWrapper : NSObject <RscMgrDelegate> {
    //redpark object
    RscMgr *rscMgr;
    
    //buffer for communication
    UInt8 rxBuffer[BUFFER_LEN];
    UInt8 txBuffer[BUFFER_LEN];
    
    
    id <RedparkWrapperDelegate> delegate;
    
    NSMutableString *serialCommand;
}

//properties
@property (nonatomic, retain) id delegate;
@property (nonatomic, retain) RscMgr *rscMgr;
@property (nonatomic, retain) NSMutableString *serialCommand;

//fn
-(void) processCommand;
-(void) sendSerial:(NSString*)cmd;
@end
