//
//  Button.h
//  Protocol
//
//  Created by Geekii on 14-9-22.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Button;

// OC中   ：代表继承， （）代表Category，<>代表protocol
@protocol ButtonDelegate <NSObject>

- (void)onClick: (Button*)button;

@end


@interface Button : NSObject

// 这个delegate为按钮的监听器
@property (nonatomic,retain,) id<ButtonDelegate> delegate;

- (void)click;

@end

