//
//  main.m
//  CopyDemo
//
//  Created by Geekii on 14-9-27.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

// 对象成员变量的copy关键字代表set方法会release旧对象，创建一个新对象;建议（成员变量如果是字符串用copy，其他变量一般用retain）

//注意：description方法不能打印self，否则会造成死循环！！

#pragma mark 拷贝字符串
void stringCopy () {
    // string 1
    NSString* str1 = [[NSString alloc] initWithFormat:@"age is %i",10 ];
    
    //mutablecopy 产生了一个新对象，计数器为1。源对象的计数器不变
    NSMutableString* str2 = [str1 mutableCopy];
    
    NSLog(@"str1 : %zi",[str1 retainCount]);
    NSLog(@"str2 : %zi",[str2 retainCount]);
    
    [str1 release];
    [str2 release];
} // 要注意的是：（同个对象的）copy方法返回的是原始对象的一个指针，即浅拷贝；而mutablecopy返回一个新对象，即深拷贝

//不管是浅拷贝还是深拷贝，都要release一次。
//copy语法的目的，改变副本的同时不会影响到原对象

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        stringCopy();
    }
    return 0;
}
