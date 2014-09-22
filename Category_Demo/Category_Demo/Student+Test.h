//
//  Student+Test.h
//  Category_Demo
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "Student.h"
// 需要注意的是：Category是Objective－c中非正式的协议，相比下正式的协议是protocol

// （Test）  代表分类名称， （） 代表的就是一个分类
@interface Student (Test)

// 分类只能扩展方法，不能扩展成员变量,如果扩展的方法与原类中方法重名，那么Category中的方法优先级高于原类。

- (void)test2;
@end
