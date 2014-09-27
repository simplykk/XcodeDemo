//
//  NSDictionary.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-27.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Student.h"

//在Objective－c中，快速创建一个对象往往都是使用：[这个对象去掉前缀的类名小写开头的字符串的一个静态方法]

void testDictCreate () {
    NSDictionary* dict = [NSDictionary dictionary]; // 返回一个不可修改的空字典
    
    NSDictionary* dict2 = [NSDictionary dictionaryWithObject:@"hello" forKey:@"key"];
    
    
    // 一个value，一个key，依次叠放
    NSDictionary* dict3 = [NSDictionary dictionaryWithObjectsAndKeys:@"v1",@"k1",@"v2",@"k2",@"v3",@"k3", nil];
    
    
    NSDictionary* dict4 = [NSDictionary dictionaryWithObjects:[NSArray arrayWithObjects:@"v1",@"v2",@"v3", nil] forKeys:[NSArray arrayWithObjects:@"k1",@"k2",@"k3", nil]];
    
    NSLog(@"%@",dict2);
    NSLog(@"%@",dict3);
    NSLog(@"%@",dict4);
}

void testDictUse () {
    NSDictionary* dict = [NSDictionary dictionaryWithObjectsAndKeys:@"v1",@"k1",@"v2",@"k2", nil];
    
    NSLog(@"cound %zi",[dict count]);
    
    id v = [dict objectForKey:@"k1"]; // 根据键取出值
    NSLog(@"value : %@",v);
    
    //返回所有的key
    NSArray* keys = [dict allKeys]; // [dict allValues]
    NSLog(@"keys %@",keys);
} //字典的用法

void testDictTraveser () {
    //第一种，for循环遍历
    NSDictionary* dict4 = [NSDictionary dictionaryWithObjects:[NSArray arrayWithObjects:@"v1",@"v2",@"v3", nil] forKeys:[NSArray arrayWithObjects:@"k1",@"k2",@"k3", nil]];
    
    for (id key in dict4) {
        id value = [dict4 objectForKey:key];
        NSLog(@"for ... \n%@->%@",key,value);
    }
    
    
    //第二种方式，迭代器遍历（key迭代器）
    NSEnumerator* enumerator = [dict4 keyEnumerator];
    id key = nil;
    while (key = [enumerator nextObject]) {
        NSLog(@"enumerator ... \n%@->%@",key,[dict4 objectForKey:key]);
    }
    //对象迭代器，同key迭代器
    
    //第三种，使用block遍历（建议）
    [dict4 enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        NSLog(@"block ... \n%@->%@",key,obj);
    }];
    
} // 字典遍历

void testMemory () {
//所有集合都是一样的，将一个对象放入这个集合中，对象会retain一次，这个集合内存被释放时，里面所有对象都自动release一次
    Student* stu1 = [Student student];
    Student* stu2 = [Student student];
    Student* stu3 = [Student student];
    
    NSDictionary* dict = [NSDictionary dictionaryWithObjectsAndKeys:stu1,@"s1",stu2,@"s2",stu3,@"s3", nil];
    
    
}
