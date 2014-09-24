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
    
    //字符串切片
    NSString* str2 = @"1,2,3,4,5";
    NSArray* array = [str2 componentsSeparatedByString:@","];
    NSLog(@"array : %@",array);
    
    
}


#pragma mark    与路径相关
void testStringWithPath () {
//    NSArray* array =  [NSArray array]; //  快速创建一个自动释放的数组
    
    NSMutableArray* components = [NSMutableArray array]; // 快速创建一个可改变的自动释放的数组
    [components addObject:@"Users"];
    [components addObject:@"MJ"];
    [components addObject:@"Desktop"];
    
    NSString* path = [NSString pathWithComponents:components];
    NSLog(@"path : %@",path);
    
    NSArray* array = [path pathComponents];// 是pathWithComponents的逆过程
    NSLog(@"array : %@",array);
    
    path = @"/users/mj/test";
    BOOL b = [path isAbsolutePath];//判断是否绝对路径，以前面是否有/判断
    NSLog(@"是否绝对路径:%i",b);
    
    NSLog(@"最后一级目录：%@",[path lastPathComponent]);
    
    NSLog(@"删除最后一级目录返回的路径:%@",[path stringByDeletingLastPathComponent]);
    
    NSLog(@"拼接一个目录后的路径：%@",[path stringByAppendingPathComponent:@"abc"]);
}

#pragma mark 扩展名处理
void testExtension () {
    NSString* str = @"/User/MJ/test.txt";
    
    NSLog(@"扩展名：%@",[str pathExtension]);
    
    NSLog(@"删除扩展名称：%@",[str stringByDeletingPathExtension]);
    
    NSLog(@"添加扩展名：%@",[str stringByAppendingPathExtension:@"mp3"]);
    
}

#pragma mark 字符串的导出
void testExport () { //  如果文件不存在，会自动创建；如果文件夹不存在，会报错;如果编码错误，会报错。
    NSString* str = @"123456";
    NSString* path = @"/Users/geekii/test.txt";
    NSError* error = nil;
    [str writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:&error];
    // atomically 原子性：代表一次性操作，首先会创建一个临时文件，一点一点写到临时文件中，再将
    //临时文件拷贝到目标文件，如果是非原子性（NO），则直接写到目标文件中；建议使用原子性,这样能保证文件安全
    if (error) {
        NSLog(@"写入失败：%@",error); // [error localizedDescription]  会返回主要错误信息
    } else {
        NSLog(@"写入成功");
    }
}

#pragma mark 测试其他用法
void testStringOther () {
    NSString* str = @"1";
    
    int a = [str intValue];
    NSLog(@"a:%i",a);
    
    NSLog(@"字符串长度（求的是字数，不是字符数）:%zi",[@"你好" length]);
    
    NSLog(@"取出第一个字符(不支持中文)：%c",[@"abc" characterAtIndex:0]);
    
    NSLog(@"转换为C语言的字符串：%s",[@"abc" UTF8String]);
}
