//
//  main.m
//  @ClassKeyword
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Book.h"
#import "Student.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Student* stu = [[Student alloc] init];
        
        Book* book = [[Book alloc] init];
        
        [stu setBook:book];
        
        [book release];
        
        Book* book2 = [[Book alloc] init];
        
        [stu setBook:book2];
        
        [book2 release];
        
        [stu release];
        
    }
    return 0;
}
