//
//  Button.m
//  Protocol
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "Button.h"

@implementation Button

- (void)dealloc {

    [_delegate release];
    //在OC中，调用super的方法一般放在最后
    [super dealloc];
}

- (void)click {
    //模拟按钮点击方法,按钮被点击了就应该通知监听器
    NSLog(@"=====  button click  =====");
    // 在OC中可以根据这个if判断调用的对象有没有这个方法    使用respondsToSelector。
    if ([_delegate respondsToSelector:@selector(onClick:)]) {
        [_delegate onClick:self];
    } else {
        NSLog(@"no implementation");
    }
        
}

@end
