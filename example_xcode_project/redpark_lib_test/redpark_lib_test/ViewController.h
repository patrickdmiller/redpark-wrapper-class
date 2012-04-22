//
//  ViewController.h
//  redpark_lib_test
//
//  Created by Patrick Miller on 4/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "ClassWithProtocol.h"
#import "redparkWrapper.h"
@interface ViewController : UIViewController <RedparkWrapperDelegate>
{
    redparkWrapper* rp;
    UIButton* go;
    UITextField* msg;
    UITextView* res;
}

@property (retain) redparkWrapper* rp;
@property (nonatomic, retain) IBOutlet UIButton* go;
@property (nonatomic, retain) IBOutlet UITextField* msg;
@property (nonatomic, retain) IBOutlet UITextView* res;

- (IBAction)go:(id)sender;

@end
