//
//  Button.m
//  Block
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "Button.h"

@implementation Button

- (void)click {
    //这里被点击，就是调用block代码
    _m_block(self);
}

@end
