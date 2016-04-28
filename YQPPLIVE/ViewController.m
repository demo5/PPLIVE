//
//  ViewController.m
//  YQPPLIVE
//
//  Created by YoKing on 16/4/27.
//  Copyright © 2016年 YQ. All rights reserved.
//

#import "ViewController.h"
#import <CommonCrypto/CommonDigest.h>
#import "CaptureStreamingViewController.h"
#import "YQDesignViewController.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *uerID;
@property (weak, nonatomic) IBOutlet UITextField *appKEy;
@property (weak, nonatomic) IBOutlet UITextField *activiID;
@property (weak, nonatomic) IBOutlet UISwitch *switchButton;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark - third view actions
- (IBAction)onStartWithActivityIdClicked:(id)sender {
    CaptureStreamingViewControllerOrientation orientation;
    if (self.switchButton.on) {
        orientation = CaptureStreamingViewControllerOrientationLandscape;
    }
    else {
        orientation = CaptureStreamingViewControllerOrientationPortrait;
    }
    
    NSBundle *bundle = [NSBundle bundleWithURL:[[NSBundle mainBundle] URLForResource:@"LCStreamingBundle" withExtension:@"bundle"]];
    CaptureStreamingViewController * viewController = [[CaptureStreamingViewController alloc] initWithNibName:@"CaptureStreamingViewController" bundle:bundle title:nil activityId:self.activiID.text userId:self.uerID.text secretKey:self.appKEy.text orientation:orientation];
    
    [self presentViewController:viewController animated:YES completion:nil];
    
}


- (IBAction)designButton:(UIButton *)sender {
    YQDesignViewController *design = [[YQDesignViewController alloc] initWithNibName:@"YQDesignViewController" bundle:nil];
    design.orientation = self.switchButton.on ? UIInterfaceOrientationLandscapeRight : UIInterfaceOrientationPortrait;
    [self presentViewController:design animated:YES completion:^{
        
    }];
}













@end
