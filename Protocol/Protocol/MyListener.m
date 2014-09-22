//
//  MyListener.m
//  Protocol
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "MyListener.h"

#import "Button.h" // 跟@class用法一致，在实现中才导入需要的文件

// 如果想编写自己的监听器，就要实现ButtonDelegate的协议（protocol）
@implementation MyListener 

//实现协议的onclick方法
- (void)onClick: (Button*)button {
    NSLog(@"===== MyListener is listenning click =====");
}
@end
