//
//  main.m
//  Category_Demo
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Student.h"
#import "Student+Test.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Student* stu  = [[Student alloc] init];
        
        [stu test];
        [stu test2];
    }
    return 0;
}
