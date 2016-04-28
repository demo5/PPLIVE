//
//  YQDesignViewController.m
//  YQPPLIVE
//
//  Created by YoKing on 16/4/27.
//  Copyright © 2016年 YQ. All rights reserved.
//

#import "YQDesignViewController.h"
#import "LCStreamingManager.h"
@interface YQDesignViewController ()<LCStreamingManagerDelegate>
@property (nonatomic,strong)LCStreamingManager *manager;
@property (weak, nonatomic) IBOutlet UIView *conntentView;
@end

@implementation YQDesignViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initManger];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void)initManger{
//    _manager = [[LCStreamingManager alloc] init];
    _manager = [LCStreamingManager sharedManager];
    _manager.delegate = self;
    CGSize size = UIInterfaceOrientationLandscapeRight == [self preferredInterfaceOrientationForPresentation] ? CGSizeMake(self.view.bounds.size.height, self.view.bounds.size.width) : CGSizeMake(self.view.bounds.size.width, self.view.bounds.size.height);
    
    [_manager configVCSessionWithVideoSize:size
                                frameRate:24
                                  bitrate:1000000
                   useInterfaceOrientation:YES];//创建推流的视频采集Session
    
    [_manager configVideoViewFrame:self.view.bounds];//设置预览图的frame
    _manager.lockOrientation = YES;//锁定摄像头
    [_manager enableManulFocus:YES];//手动对焦
    
    //将推流的预览视图添加到开发者提供的一个view中
    [self.conntentView addSubview:[_manager videoView]];
    
}
//屏幕方向
- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    if (self.orientation == UIInterfaceOrientationPortrait || self.orientation == UIInterfaceOrientationPortraitUpsideDown) {
        return UIInterfaceOrientationPortrait;
    }
    else {
        return UIInterfaceOrientationLandscapeRight;
    }
}
//推流
- (IBAction)push:(UIButton *)sender {
    sender.selected = !sender.selected;
    if (sender.isSelected) {//开始推流
        [_manager requestVidiconInfoWithID:@"A20160427000011t" userId:@"834847" secretKey:@"15b0766b6ac46ac83af7e37ebd394b13" completed:^(BOOL isSuccess, NSArray *items, NSString *errorCode, NSString *errorMsg) {
            NSLog(@"items:------->%@",items);
            NSLog(@"errorCode:------->%@",errorCode);
            NSLog(@"errorMsg:------->%@",errorMsg);
            if (isSuccess) {
                NSLog(@"success");
                for (int i = 0; i < items.count; i ++) {
                    LCVidiconItem *vidiconItem = items[i];
                    if (vidiconItem.enable) {
                        [_manager startStreamingWithLCVidiconItem:vidiconItem];
                        break;
                    }
                }
            }
            else {
                NSLog(@"error");
                NSLog(@"%@", errorCode);
            }
            
        }];
    }else{//暂停推流
        [_manager stopStreaming];
    }
}
- (IBAction)back:(UIButton *)sender {
    [_manager stopStreaming];
    _manager.delegate = nil;
    [_manager cleanSession];
    [self dismissViewControllerAnimated:YES completion:^{
        
    }];
}


#pragma mark - delegate
- (void) connectionStatusChanged: (LCStreamingSessionState) sessionState{
    NSLog(@"sessionState:-------->%ld",(long)sessionState);
//    LCStreamingSessionStateNone,
//    LCStreamingSessionStatePreviewStarted,
//    LCStreamingSessionStateStarting,
//    LCStreamingSessionStateStarted,
//    LCStreamingSessionStateEnded,
//    LCStreamingSessionStateError
    switch (sessionState) {
        case LCStreamingSessionStateNone:
            
            break;
        case LCStreamingSessionStatePreviewStarted:
            
            break;
        case LCStreamingSessionStateStarting:
            
            break;
        case LCStreamingSessionStateStarted:
            
            break;
        case LCStreamingSessionStateEnded:
            
            break;
        case LCStreamingSessionStateError:
            
            break;
        default:
            break;
    }
}

@end
