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

@end
