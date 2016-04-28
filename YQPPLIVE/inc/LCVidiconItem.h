//
//  LCVidiconItem.h
//  LeCloudStreaming
//
//  Created by CC on 15/7/6.
//  Copyright (c) 2015年 Letv. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 摄像机位Item
 */
@interface LCVidiconItem : NSObject

@property (nonatomic,readonly) NSString * machine;
@property (nonatomic,readonly) NSString * liveId;
@property (nonatomic,readonly) NSString * streamId;
@property (nonatomic,readonly) NSString * pushUrl;
@property (nonatomic,readonly) BOOL enable;

+(LCVidiconItem *)itemWithDictionary:(NSDictionary *)dict;

@end
