//
//  Student.m
//  @ClassKeyword
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "Student.h"

#import "Book.h"

@implementation Student

//@synthesize book = _book;

//- (void)setBook:(Book *)book {
//    
//    if (_book != book) {
//        [_book release];
//        _book = [book retain];
//    }
//}

//- (Book*)book {
//    return _book;
//}

- (void)dealloc {
    [super dealloc];
    
    //self.book = nil;
    //[self setBook:nil];
    [_book release];
}

+ (id)student {
    Student* stu = [[Student alloc] init];
    [stu autorelease]; // 按照：谁创建对象谁释放的法制，我们要在内部进行释放，因此需要用：autorelease
    return stu;
}

+ (id)studentWithAge: (int)age {
//    Student* stu = [self student]; // 在OC中，self指向谁是看谁调用这个方法，因此这里的self指向调用这个方法的Student类
    Student* stu = [[[Student alloc] init] autorelease];
    [stu setAge:age];
    return stu;
}

@end
