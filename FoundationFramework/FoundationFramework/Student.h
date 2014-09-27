//
//  Student.h
//  FoundationFramework
//
//  Created by Geekii on 14-9-26.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Student : NSObject

@property (nonatomic,retain) NSString* name;

+ (id) student;

- (void) test2: (NSString*) str;

- (void) test;

@end
