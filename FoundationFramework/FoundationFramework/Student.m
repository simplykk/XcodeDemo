//
//  Student.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-26.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "Student.h"

@implementation Student

+ (id)student {
    return [[Student alloc] autorelease];
}

- (void)test2:(NSString *)str {
    NSLog(@"test2 被调用了%@",str);
}

- (void) test {
    NSLog(@"%@被调用了",self);
}

- (void) dealloc {
    NSLog(@"%@被销毁了",self);
    [super dealloc];
}

@end
