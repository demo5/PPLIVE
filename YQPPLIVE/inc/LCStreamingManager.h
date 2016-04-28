//
//  LCStreamingManager.h
//  LeCloudStreaming
//
//  Created by CC on 15/7/6.
//  Copyright (c) 2015年 Letv. All rights reserved.
//

/**
 * @file	LCStreamingManager.h
 * @brief	推流SDK头文件（无皮肤版本的）.
 * @author	letvCloud_iOSTeam
 * @version	1.0
 * @date	2015-08-11
 *
 * # update （更新日志）
 *
 * [2015-08-11] <letvCloud> v1.0
 *
 * + v1.0版发布.
 *
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LCVidiconItem.h"

typedef NS_ENUM(NSInteger, LCStreamingSessionState)
{
    LCStreamingSessionStateNone,
    LCStreamingSessionStatePreviewStarted,
    LCStreamingSessionStateStarting,
    LCStreamingSessionStateStarted,
    LCStreamingSessionStateEnded,
    LCStreamingSessionStateError
};


typedef NS_ENUM(NSInteger, LCCamareOrientationState)
{
    LCCamareOrientationStateFront,
    LCCamareOrientationStateBack
};

@protocol LCStreamingManagerDelegate <NSObject>

@required
- (void) connectionStatusChanged: (LCStreamingSessionState) sessionState;

@optional
- (void) detectedThroughput: (NSInteger) throughputInBytesPerSecond videoRate:(NSInteger) rate;
- (CVPixelBufferRef)newPixelBufferFromPixelBuffer:(const CVPixelBufferRef)pixelBuffer;
@end

/// 推流SDK头文件.
@interface LCStreamingManager : NSObject
/// 委托
@property (nonatomic,weak) id<LCStreamingManagerDelegate> delegate;
/// 是否锁定摄像头的拍摄方向
@property (nonatomic,assign) BOOL lockOrientation;
/// vidoeSize 设置视频的大小（下次推流时生效）
@property (nonatomic,assign) CGSize videoSize;

//音量增益，大于0；未初始化时返回-1
@property (nonatomic, assign) CGFloat gain;

//对焦(0,0) is top-left, (1,1) is bottom-right
@property (nonatomic, assign) CGPoint focusPoint;

//启用手动对焦，默认未启用
- (void)enableManulFocus:(BOOL)enable;

/*!
 创建Manager对象
 */
+ (LCStreamingManager *)sharedManager;

/*!
 获取机位信息
 aId为活动ID
 items内对象为LCVidiconItem
 */
- (void)requestVidiconInfoWithID:(NSString *)aId
                          userId:(NSString *)userId
                       secretKey:(NSString *)secretKey
                       completed:(void (^) (BOOL isSuccess,NSArray * items,NSString *errorCode,NSString *errorMsg))block;

/*!
 获得在线用户信息
 */
- (BOOL)startPollOnlineUserNumberWithGotOnlineAudienceNumber:(void (^)(long userNumber)) success;

/*!
 *  停止刷新在线人数
 */
- (void)stopPollOnlineUserNumber;

/*!
 *  创建推流的视频采集Session
 *
 *  @param size                    视图大小
 *  @param frameRate               推流视频的帧率
 *  @param bitrate                 推流的视频码率
 *  @param useInterfaceOrientation 是否使用用户界面的方向作为视频信息采集的方向，否则将使用硬件方向
 */
- (void)configVCSessionWithVideoSize:(CGSize)size
                           frameRate:(int)frameRate
                             bitrate:(int)bitrate
             useInterfaceOrientation:(BOOL)useInterfaceOrientation;

/*!
 获取视频采集的视图
 */
- (UIView *)videoView;

/*!
 当前视频预览图
 */
- (UIImage *)currentCameraPreviewImage;

/*!
 设置预览视图的Frame
 */
- (void)configVideoViewFrame:(CGRect)frame;

/*!
 * 开始推流
 *
 * @param item  机位信息
 */
- (void)startStreamingWithLCVidiconItem:(LCVidiconItem *)item;

/*!
 * 使用rtmp地址开始推流
 *
 * @param urlString     推流使用的rtmp地址
 */
- (void)startStreamingWithRtmpAdress:(NSString *)urlString;

/*!
 结束推流
 */
- (void)stopStreaming;

/*!
 清理session
 */
- (void)cleanSession;

/*!
 * 设置闪光灯
 *
 * @param open  是否开启；默认不开启闪光灯
 */
- (void)setTorchOpenState:(BOOL)open;
- (BOOL)torchOpenState;

/*!
 * 设置静音
 *
 * @param mute  是否静音；默认不静音
 */
- (void)setMute:(BOOL)mute;

/*!
 设置镜头方向
 */
- (void)setCamareOrientationState:(LCCamareOrientationState)state;

@end
