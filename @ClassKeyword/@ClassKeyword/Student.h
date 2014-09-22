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

@interface Student : NSObject
//{
//    Book*  _book;
//}

//- (void)setBook: (Book*)book;

//- (Book*)book;

//@property Book *book;
@property (retain) Book* book;
//@property (assign) Book* book; // 默认是assign，使用set方法时直接赋值
//@property (retain) Book* book; // 如果使用了retain关键字，则在实现中会自动在set方法中检验是否已有对象并release旧对象

@end
