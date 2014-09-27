//
//  User.m
//  FoundationFramework
//
//  Created by Geekii on 14-9-27.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "User.h"

@implementation User

+ (id) userWithFirstName:(NSString *)firstName AndLastName:(NSString *)lastName {
    User* user = [[User alloc] autorelease];
    [user setFirstName:firstName];
    [user setLastName:lastName];
    
    return user;
}

- (NSComparisonResult) compareUser:(User *)user {
    //先按照LastName排序，再按FirstName
    NSComparisonResult lastNameRes = [[self lastName] compare:[user lastName]];
    if (lastNameRes == NSOrderedSame) {
        return [[self firstName] compare:[user firstName]];
    }
    return lastNameRes;
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"[%@ %@]", [self firstName],[self lastName]];
}

- (void)dealloc {
    [_firstName release];
    [_lastName release];
    [super dealloc];
}

@end
