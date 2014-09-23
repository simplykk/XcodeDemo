//
//  main.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "Struct.part"
#import "NS_Class.part"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        // C语言中的结构体定义
        /*
         
        struct Date {
            
            int year;
            int month;
            int day;
        };
        struct Date d = {2014,9,22};
        d.year = 2013;
         
         */
        
        testRange();
        testPoint();
        
        testNSString();
        
        testStringCreate2();
        
        testStringWithNET();
        
    }
    return 0;
}
