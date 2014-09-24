//
//  Framework.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//


//  Foundation框架中的结构体
// NSPoint(代表控件坐标), NSRange（描述NSString）, NSSize（描述控件尺寸）,NSRect(描述
// 控件坐标和尺寸，包含了NSPoint和NSSize) : Foundation框架中比较重要的结构体


#import <Foundation/Foundation.h>



void test1 () {
    typedef struct Date {
        int year;
        int month;
        int day;
    } MyDate;
    
    
    
    MyDate d = {2011,2,1};
    d.month = 11;
}

void testRange () {
    //NSString* str = @"I love Objective-c";
    //    NSRange range = {1,3};
    NSRange range = NSMakeRange(7, 2); // 这是在OC中最常用的方法
    
    //    NSLog(@"location %zi, length %zi",range.location,range.length);
    NSLog(@"%@",NSStringFromRange(range));
}

void testPoint () {
    //    NSPoint p;
    //    p.x = 1;
    //    p.y = 10;
    
    //    NSPoint p = NSMakeRange(10, 9);
    
    // 最常用的是这种方法，因为IOS中所有的控件都是画出来的，而OC中画图有关的框架最重要的
    // 就是CoreGraphics这个框架，里面的类都是以CG开头
    NSPoint p = CGPointMake(10, 8);
    
    NSLog(@"%@",NSStringFromPoint(p));
}

void testSize () {
    //    NSSize size;
    //    size.height = 100;
    //    size.width = 100;
    
    //    NSSize size = NSMakeSize(199, 111);
    
    NSSize  size = CGSizeMake(111, 333);
    
    NSString* str = NSStringFromSize(size);
    
    NSLog(@"%@",str);
}

void testRect () {
    //    NSRect rect; // CGRect rect;
    //    rect.origin.x = 10;
    //    rect.origin.y = 11;
    //    rect.size.height = 100;
    //    rect.size.width = 199;
    
    //    rect.origin = {1,2};//注意！这样赋值是错误的，不允许对一个整体对象直接赋值
    
    //    NSRect rect = NSMakeRect(100, 100, 100, 100);
    
    NSRect rect = CGRectMake(100, 100, 100, 100); // 最常用
    NSLog(@"%@",NSStringFromRect(rect));
    
}

