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
        
        //[book release];
        
        Book* book2 = [[Book alloc] init];
        
        [stu setBook:book2];
        
        //[book2 release];
        
        //[stu release];
        
        [book autorelease];
        [book2 autorelease];
        [stu autorelease];
        
        Student* stuWithAge = [Student studentWithAge:20];
        NSLog(@"stu age : %i",[stuWithAge age]);
        
        //特别提示，不要在循环中使用自动释放池，因为又可能会产生大量的对象，等待自动释放池有延时会影响程序性能，应当手动释放：
        for (int i = 0; i < 100; i++) {
            // do something...
            Book* bk = [[Book alloc] init];
            [bk release];
        }
        
        NSLog(@"----------------------------------loop...");
    }
    NSLog(@"finished...");
    return 0;
}
