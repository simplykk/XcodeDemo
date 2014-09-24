//
//  NSString.h
//  FoundationFramework
//
//  Created by Geekii on 14-9-24.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

void testCase () {
    // ============= NSString 的常用方法
    
    // NSString 的大小写处理
    NSString* small_str = @"hello";
    
    NSLog(@"%@",[small_str uppercaseString]); // lowercaseString,capitalizedString首字母大写

}

void testCompare () {
    // NSString 的比较
    //isEqualToString  仅仅比较两个字符串内容是否一致，
    BOOL isequalToString = [@"Abc" isEqualToString:@"Abc"]; // YES 1, NO 0
    NSLog(@"isequalToString: %i",isequalToString);
    // compare
    NSLog(@"compare:%i",[@"Abc" compare:@"abc"] == NSOrderedAscending); // 返回值：NSComparisonResult{  根据Ascii比较
    //  NSOrderedSame 两个字符串相同
    //  NSOrderedAscending 代表右边的字符串比左边大
    //  NSOrderedDescending 代表左边的比右边大}
    
    //caseInsensitiveCompare 跟compare比较相似，忽略大小写
}

#pragma mark 字符串的搜索
void  testSearch () {
     // NSString 搜索字符串
    NSString* str = @"123234.part";
    
    NSLog(@"是否以12开头：%i",[str hasPrefix:@"12"]);
    NSLog(@"是否以part结尾:%i",[str hasSuffix:@".part"]);
    
    NSRange range = [str rangeOfString:@"23"];
    // 如果找不到，返回一个location 为NSNotFound常量,location为NSIntegerMax，length为0
    NSLog(@"检查是否包含23，返回它的范围：%@",NSStringFromRange(range));
    
    NSRange backRange = [str rangeOfString:@"23" options:NSBackwardsSearch];
    NSLog(@"从尾部开始搜索23:%@",NSStringFromRange(backRange));
    
}


void subString () {
    NSString* str = @"123456";
    NSString* sub_str = [str substringFromIndex:3]; //从fromindex开始截取
    
    NSLog(@"%@",sub_str);
    NSLog(@"从尾部开始截取：%@",[str substringToIndex:3]); // 从头部开始截取到toindex前
   
    //指定范围进行截取
    NSRange range = NSMakeRange(2, 3); // 从下标2开始，截取3个字符

    NSLog(@"指定范围： %@",[str substringWithRange:range]);
}
