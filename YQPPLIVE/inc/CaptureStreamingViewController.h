//
//  CaptureStreamingViewController.h
//  LeCloudStreamingDemo
//
//  Created by CC on 15/7/8.
//  Copyright (c) 2015年 Letv. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(int, CaptureStreamingViewControllerOrientation) {
    CaptureStreamingViewControllerOrientationPortrait,
    CaptureStreamingViewControllerOrientationLandscape
};

typedef NS_ENUM(int, CaptureStreamingViewControllerPreset) {
    CaptureStreamingViewControllerPreset1280x720,
    CaptureStreamingViewControllerPreset640x360
};

@interface CaptureStreamingViewController : UIViewController

- (id)initWithNibName:(NSString *)nibNameOrNil
               bundle:(NSBundle *)nibBundleOrNil
                title:(NSString *)title
           activityId:(NSString *)activityId
               userId:(NSString *)userId
            secretKey:(NSString *)secretKey
          orientation:(CaptureStreamingViewControllerOrientation) orientation;

- (id)initWithRTMPURL:(NSString *)rtmpURL
                title:(NSString *)title
          orientation:(CaptureStreamingViewControllerOrientation) orientation;

//预设的分辨率，默认值为CaptureStreamingViewControllerPreset1280x720
@property (nonatomic, assign) CaptureStreamingViewControllerPreset preset;
//视频流比特率，默认值为1000000bps
@property (nonatomic, assign) int bitRate;
//每秒的视频帧数，默认值为25fps
@property (nonatomic, assign) int frameRate;
//当前预览视图的图像（只读）
@property (nonatomic, readonly) UIImage *currentCameraPreviewImage;

@end