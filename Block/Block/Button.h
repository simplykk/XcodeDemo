//
//  Button.h
//  Block
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Button;

// 第一步：首先定义一个block类型
//typedef void (^buttonBlock) (Button* btn);
typedef void (^buttonBlock) (Button*);

@interface Button : NSObject

//第二步：声明一个block属性，这里本来不应该用assign，暂时使用assign
@property (nonatomic,assign) buttonBlock m_block;

//模拟按钮点击
- (void)click;

@end
