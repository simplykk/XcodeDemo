//
//  main.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "Student.h"

#import "Struct.h"
#import "NS_Class.h"
#import "NSString.h"
#import "NSMutableString.h"
#import "NSArray.h"
#import "NSDictionary.h"

//除了上面的对象，还有NSNumber,NSValue,NSNUll,NSDate等...


void testNSNumber () {
    NSNumber* number = [NSNumber numberWithInt:1]; // 将int类型包装成一个NSNumber对象(打包)
    NSLog(@"%@",number);
    
    int n1 = [number intValue]; // 解包
    
}//OC中不支持自动打包解包，需要手动将对象进行封装和解封装

void testNSValue () {
    CGPoint point = CGPointMake(10, 10);
    
    typedef struct {
        int age;
        char* name;
    } Person;
    Person p = {10,"Jack"};
    char* type = @encode(Person); //这一句代码表示，根据这个结构体的类型生成它的类型名称
    
    NSValue* value = [NSValue valueWithPoint:point];
    NSValue* mValue = [NSValue value:&p withObjCType:type];
    
    NSLog(@"value: %@",value);
    
    Person p2;
    [mValue getValue:&p2]; //  解包
    NSLog(@"%s",p2.name);
//    NSLog(@"mValue : %@",mValue);
    
    NSLog(@"%s",[mValue objCType]); // 取出类型描述字符串
    
    //需要注意的是，假定服务器传输的是JSON数据，如果里面包含有null值，那么这个值在OC中干脆就不会解析，这点需要注意；
    
    
}//NSNumber只支持基本类型，不支持结构体，如需支持结构体，就要使用NSNumber的父类，NSValue（可包装任何值,包括OC对象）

// 注意：对象的比较如果只用＝＝比较，则比较的是值和地址是否相等。
void testNSNull () {
    //在集合中，nil有特殊意义，当想表达一个值为空时，就要使用NSNull
    NSNull* null = [NSNull null];
    
    NSLog(@"null :%@",null);
} //  需要注意的是，这个NSNull永远返回同一个对象（单例模式），即，不同地方引用的这个对象都是同一个地址
//单例模式有三个条件：私有的构造方法，静态生成方法，静态的成员变量


void testDate () {// NSData 相当于java中的字节数组
    NSDate* date = [NSDate date]; // 返回的是当前时间
    NSLog(@"date %@",date);
    
//    NSTimeInterval //  是以秒记单位的
    NSDate* date2 = [NSDate dateWithTimeIntervalSinceNow:10]; // 这个方法返回的时间会在当前时间加上10秒
    NSLog(@"date+10second : %@",date2);
    
    NSDate* date3 = [NSDate dateWithTimeIntervalSince1970:10]; // 计算机诞生的时间（1970-1-1 0:00）
    
    NSDate* date4 = [NSDate distantFuture]; // 返回将来比较遥远的一个随机时间
    
    NSDate* date5 = [NSDate distantPast]; //返回遥远的过去
    
    NSTimeInterval interval = [date timeIntervalSince1970];
    NSLog(@"interval %lf",interval);
    
    //日期格式化
    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    
    [formatter setLocale:[NSLocale localeWithLocaleIdentifier:@"zh_CN"]];//有时需要设置时区
    
    NSLog(@"date string %@",[formatter stringFromDate:date]);
    
    [formatter release];
}

void testNSObject () {
    id stu = [[[Student alloc] init] autorelease];
    BOOL res = [stu isKindOfClass:[Student class]]; // 判断改对象是不是某个类或它的子类
//    [stu isMemberOfClass:[Student class]]; // 这个方法比较严格，判断对象是不是该类
    
    
    //延迟2秒调用方法
    
    [stu performSelector:@selector(test2:) withObject:@"abc" afterDelay:2];
    //[NSThread sleepForTimeInterval:5];

    //OC中的反射
    //1.类名的反射，只知道类名字符串，创建出一个该类对象
    NSString* cls = @"Student";
    Class clazz = NSClassFromString(cls);
    
    id obj = [[[clazz alloc] init] autorelease];
    NSLog(@"打印出类：%@",obj);
    
    NSString* clsStr =  NSStringFromClass([Student class]);
    NSLog(@"clsStr : %@",clsStr);
    
    //2.方法的反射
    NSString* methodStr = @"test";
    SEL selector = NSSelectorFromString(methodStr);
    [stu performSelector:selector];
    

}

//#import "Struct.part"
//#import "NS_Class.part"

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
        
        
//        testRange();
//        testPoint();
//
//        testNSString();
//        
//        testStringCreate2();
//        
//        testStringWithNET();
        
//        testCompare();
//        
//        testSearch();
//        subString();
//        testStringWithPath();
//        testExtension();
//        testStringOther();
//        testExport();
        
        
        //nsmutablestring
//        testMStringCreate();
        
        //nsarray
//        testNSArray();
//        testArrayUse();
//        testArrayMemory();
//        testSendMSG();
//        testArrayTraverse();
//        testArrayDerive();
//        testArrayOther();
//        testArraySort();
//        testNSMutableArray();
        
        
        /// test dictionary
//        testDictCreate();
//        testDictUse();
//        testDictTraveser();
//        testMemory();
        
        
        //other
//        testNSNumber();
//        testNSValue();
//        testNSNull();
//        testDate();
        testNSObject();
        
    }
    return 0;
}
