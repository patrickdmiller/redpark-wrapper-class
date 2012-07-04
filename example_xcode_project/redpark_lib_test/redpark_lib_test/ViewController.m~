//
//  ViewController.m
//  redpark_lib_test
//
//  Created by Patrick Miller on 4/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize rp, go, msg, res;
- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    rp = [[redparkWrapper alloc] init];
    [rp setDelegate:self];
    
    [res setText:@"nothing yet"];
    
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

- (IBAction)go:(id)sender{
    [rp sendSerial:[msg text]];
}

// delegete ******************** /
 
-(void) newMessageAvailable:(NSString*)msg{
    [res setText:msg];
}


@end
