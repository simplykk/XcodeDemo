//
//  MyListener.h
//  Protocol
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import "Button.h"
@protocol ButtonDelegate;  // 这句的用法类似与@class，只有真正用到协议的时候才使用＃import


@interface MyListener : NSObject <ButtonDelegate>

@end
