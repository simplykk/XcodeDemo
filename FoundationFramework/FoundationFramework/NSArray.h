//
//  NSArray.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-26.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Student.h"
#import "User.h"

void testNSArray () {
    NSArray* array = [NSArray array]; // 快速创建方法
    
    NSArray* arrayWithObj = [NSArray arrayWithObject:@"123"];
    
    NSArray* arrayWithObjs = [NSArray arrayWithObjects:@"123",@"456", nil];
    
    NSArray* arrayAlloc = [[NSArray alloc] init];
    
    [arrayAlloc release];
    
    NSUInteger count = [arrayWithObjs count];
    
    NSLog(@"%@ count : %zi",arrayWithObjs,count);
} //  NSArray 只允许装OC对象，不允许基本数据和空值(空值代表数组元素的结束)


void testArrayUse () {
    NSArray* array = [NSArray arrayWithObjects:@"a",@"b",@"c", nil];
    if ([array containsObject:@"a"]) {
        NSLog(@"包含了字符串A");
    }
    
    id obj = [array lastObject];
    NSLog(@"last obj %@",obj);
    
    NSLog(@"at index 1 %@",[array objectAtIndex:1]);
    
    NSLog(@"c index %zi",[array indexOfObject:@"c"]);
    
}

void testArrayMemory () {
    Student* stu1= [[Student alloc] init];
    Student* stu2= [[Student alloc] init];
    Student* stu3= [[Student alloc] init];
    
    
    NSLog(@"before added : %zi",[stu1 retainCount]);
    
    NSArray* array = [[NSArray alloc] initWithObjects:stu1,stu2,stu3, nil];
    NSLog(@"by added : %zi",[stu1 retainCount]);
    
    NSLog(@"count = %zi",[array count]);
    
    [stu1 release];
    [stu2 release];
    [stu3 release];
    [array release];
} // 非常重要的一点！当一个对象放入List集合中时，这个对象的计数器会＋1(retain)，
//但是，当这个数组被释放内存时，这个数组里面所有元素都会被release一次

void testSendMSG() {
    Student* stu1 = [Student student];
    Student* stu2 = [Student student];
    Student* stu3 = [Student student];
    
    NSArray* array = [NSArray arrayWithObjects:stu1,stu2,stu3, nil];
    
    
    
    [array makeObjectsPerformSelector:@selector(test)]; //  给所有student里调用test方法
    
    // 带参数发送消息，不错只限制传递一个参数
    [array makeObjectsPerformSelector:@selector(test2:) withObject:@"123"];
} //给一个数组里所有元素调用同一个方法(发送同一个消息)

void testArrayTraverse () {
    NSArray* array = [NSArray arrayWithObjects:@"1",@"2",@"3", nil];
    
    for (int i = 0; i < [array count]; i++) {
        NSLog(@"i位置的元素：%@",[array objectAtIndex:i]); // OC中的id类型相当于C语言中的void*
    } // 第一种遍历方法
    
    //第二种遍历方法
    for (id obj in array) {
        NSLog(@"数组->%@",obj);
    }
    
    //第三种方法，OC推荐的，是一种block机制.这个方法，每遍历一个元素都会调用一次这个block
    //这里提到一个小技巧：如果有遇到需要生成的代码段（颜色较深的块），双击就会自动生成
    [array enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        //第一个参数：当前遍历到的对象，第二个参数：当前遍历的位置，第三个：是否停止遍历
        NSLog(@"%zi-->%@",idx,obj);
//        *stop = YES; // 如果需要停止循环，则使外部的stop变量为YES
    }];
    
    
    //第四种：迭代器遍历
    NSEnumerator* enumerator = [array objectEnumerator];
//    [array reverseObjectEnumerator];//反序迭代器
//    [enumerator allObjects];//返回迭代器所有元素
    id iobj = nil;
    while (iobj = [enumerator nextObject]) {
        NSLog(@"迭代器遍历：%@",iobj);
    }
    
    
}// 遍历数组

void testArrayDerive () {
    NSArray* array = [NSArray arrayWithObjects:@"1",@"3",nil];
    
    NSArray* array2 = [array arrayByAddingObject:@"2"];
    
    NSArray* array3 = [array arrayByAddingObjectsFromArray:array2];
    
    
    NSArray* array4 = [array3 subarrayWithRange:NSMakeRange(1, 3)];

    
    NSLog(@" derive array %@, array3 : %@,array4:%@",array2,array3,array4);
} //  array派生方法

void testArrayOther () {
    NSArray* array = [NSArray arrayWithObjects:@"1",@"2",@"3", nil];
    
    NSString* str = [array componentsJoinedByString:@","];// 利用分隔符拼接数组元素
    
    //从array中生成xml文件，同样读取也需要符合格式的XML文件
//    [array writeToFile:@"/Users/geekii/" atomically:YES];
    
    
    
    NSLog(@"str : %@",str);
}//其他方法

void testArraySort() {
    NSArray* array = [NSArray arrayWithObjects:@"1",@"3",@"2", nil];
    
    NSArray* array2 = [array sortedArrayUsingSelector:@selector(compare:)];//最简单的排序
    
    NSArray* array3 = [NSArray arrayWithObjects:[User userWithFirstName:@"Ada" AndLastName:@"Wong"],[User userWithFirstName:@"Jack" AndLastName:@"Lemons"],[User userWithFirstName:@"Damo" AndLastName:@"Swift"], nil];
    
    [array3 sortedArrayUsingSelector:@selector(compareUser:)];
    
    NSLog(@"sorted array : %@",array2);
    
    NSLog(@"sorted user : %@",array3);
    
    //使用block进行排序
    [array3 sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2) {
        //先按照LastName排序，再按FirstName
        NSComparisonResult lastNameRes = [[obj1 lastName] compare:[obj2 lastName]];
        if (lastNameRes == NSOrderedSame) {
            return [[obj1 firstName] compare:[obj2 firstName]];
        }
        return lastNameRes;

    }];
    
    
}// 数组排序

void testNSMutableArray () {
    NSMutableArray* array = [NSMutableArray arrayWithObjects:@"1", nil];
    
    [array addObject:@"2"]; // 添加
    [array removeObject:@"1"]; // 移除
    [array removeAllObjects]; //清空
    [array addObject:@"ddd"];
    [array replaceObjectAtIndex:0 withObject:@"abc"];
    NSLog(@"%@",array);
}



