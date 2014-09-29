//
//  AppController.h
//  CocoaFirstDemo
//
//  Created by Geekii on 14-9-29.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

// Cocoa 程序需要导入包
#import <Cocoa/Cocoa.h>

@interface AppController : NSObject {
    // 这里的IBOutlet和IBAction不是用于编译的，目的是为了提供编写代码的人和Interface builder可阅读的标记
    IBOutlet NSTextField* _textField;
    IBOutlet NSTextField* _resultField;
}

- (IBAction)uppercase:(id)sender;
- (IBAction)lowercase:(id)sender;


@end
