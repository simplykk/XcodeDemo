//
//  Class.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

// 再次强调，谁调用alloc这个方法（Message，消息），谁就要调用release方法

//Foundation 中的常用的类：NSString


#import <Foundation/Foundation.h>



void testNSString () {
NSString* str1 = @"a string"; // 最简单方式，不过这样创建的是一个字符串常量，不能被改变,不需要管理内存

//    NSString* str2 = [[NSString alloc] init]; //字符串变量，不过需要手动释放内存

//    NSString* str3 = [[NSString alloc] initWithString:@"hello"]; // 跟第二种差不多


//这种方式可以将C语言字符串转化成OC字符串对象，这种方式在数据库操作中常用
//    NSString* str4 = [[NSString alloc] initWithUTF8String:"C language string"];

//    NSString* str5 = [[NSString alloc] initWithFormat:@"age is %i",1];

//str1 = @"ddd";

NSLog(@"%@",str1);


//    [str2 release];
//    [str3 release];
//    [str4 release];
//    [str5 release];
}

void testStringCreate2 () {
//定义一个NSError对象
NSError* error;


//从文件中读取文本
NSString* path = @"/Users/geekii/code/Xcode/MacOS/XcodeDemo/test.txt";
//    NSString* str = [NSString stringWithContentsOfFile:path]; // 这个方法已经过时，不能解析中文

//指定编码格式为UTF－8
NSString* str = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:&error];

if (nil == error) { // 没有错误信息
NSLog(@"读取文件成功:%@",str);
} else {
NSLog(@"读取文件失败:%@",error);
}

//    NSLog(@"%@",str);
}

void testStringWithNET () {
//注意，URL方式读取文件，如果是本地要以：file:// 为前缀，另外的有http:// ,ftp:// ,mtp:// ...
NSURL* url = [NSURL URLWithString:@"file:///Users/geekii/code/Xcode/MacOS/XcodeDemo/test.txt"]; // 请求本地文件URL

NSURL* remoteUrl = [NSURL URLWithString:@"http://www.baidu.com"];//请求远程文件URL

NSString* str = [NSString stringWithContentsOfURL:url encoding:NSUTF8StringEncoding error:nil];

NSString* baidu = [NSString stringWithContentsOfURL:remoteUrl encoding:NSUTF8StringEncoding error:nil];

NSLog(@"%@",str);

NSLog(@"baidu : \n\n%@",baidu);


}
