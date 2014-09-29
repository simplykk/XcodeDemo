//
//  AppController.m
//  CocoaFirstDemo
//
//  Created by Geekii on 14-9-29.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import "AppController.h"

@implementation AppController

- (instancetype)init
{
    self = [super init];
    if (self) {
        NSLog(@"init : text %@ / result %@",_textField,_resultField);
    }
    return self;
} // init

//注意Cocoa在完成链接后会向controller发送这个消息，而在init方法中UI控件获得的都为空值，
//任何有关UI初始化的操作都不能在init中执行，应该在awakeFromNib中执行
- (void)awakeFromNib
{
    NSLog(@"awakeFromFetch : text %@ / result %@",_textField,_resultField);
    
    _textField.stringValue = @"Enter text here"; // 设置文本框默认值
    _resultField.stringValue = @"Results"; //  设置标签默认值
    
    NSDate* date = [NSDate date];
    NSLog(@"today is %@",date);
} // awakeFromNib

- (void)lowercase:(id)sender {
    NSString* original = _textField.stringValue;
    
    NSString* lowercase = [original lowercaseString];
    
    _resultField.stringValue = lowercase;
} // lowercase

- (void)uppercase:(id)sender {
    NSString* original = _textField.stringValue;
    
    NSString* uppercase = [original uppercaseString];
    
    _resultField.stringValue  = uppercase;
} // uppercase

@end
