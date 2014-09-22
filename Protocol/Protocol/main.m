//
//  main.m
//  Protocol
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Button.h"
#import "ButtonListener.h"
#import "MyListener.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        
        Button* button =  [[Button alloc] init]; // 初始化一个按钮
        
        ButtonListener* listener = [[ButtonListener alloc] init]; // 初始化一个监听器
        
        [button setDelegate:listener]; // button代理，返回遵守协议的对象
        
        //[listener onClick];
        [button click];
        
        ///说明MyListener监听到按钮点击的事件
        MyListener* mListener = [[MyListener alloc] init];
        [button setDelegate:mListener];
        [button click];
        
        [mListener release];
        [listener release];
        [button release];
    }
    return 0;
}
