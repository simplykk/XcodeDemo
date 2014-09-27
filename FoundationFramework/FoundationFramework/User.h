//
//  User.h
//  FoundationFramework
//
//  Created by Geekii on 14-9-27.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface User : NSObject

@property (nonatomic, retain) NSString* firstName;

@property (nonatomic,retain) NSString* lastName;

+ (id)userWithFirstName:(NSString*)firstName AndLastName:(NSString*)lastName;

- (NSComparisonResult) compareUser:(User*)user; // 如果要实现比较或者数组排序，排序的方法返回值必须为NSComparisonResult

@end
