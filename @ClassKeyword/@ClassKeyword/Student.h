//
//  Student.h
//  @ClassKeyword
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import "Book.h"
@class Book;

@interface Student : NSObject {
    Book*  _book;
}

- (void)setBook: (Book*)book;

- (Book*)book;

//@property Book *book;

@end
