//
//  NSMutableString.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-26.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark 可变字符串的创建
void testMStringCreate () {
    // 预先分配10个字数的存储空间
    NSMutableString* str = [[NSMutableString alloc] initWithCapacity:10];
    //设置字符串内容
    [str setString:@"1234"];
    
    //拼接一个字符串
    [str appendString:@"567"];
    [str appendFormat:@"age is %i and height is %f",12,1.44f];
    
    //替换字符串
    NSRange range = [str rangeOfString:@"age"];
    [str replaceCharactersInRange:range withString:@"no"];
    
    // 插入字符串
    [str insertString:@"hello" atIndex:range.location];
    
    //删除字符串
    [str deleteCharactersInRange:range];
    
    NSLog(@"%@",str);
    
    [str release];
    
}
