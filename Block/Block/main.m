//
//  main.m
//  Block
//
//  Created by Geekii on 14-9-23.
//  Copyright (c) 2014年 Geekii. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Button.h"

typedef int (^my_sum)  (int,int); // 定义一个my_sum的block类型,这样的好处是后面可以无限声明多个block

void test() {
    //如果外部的变量用__block关键字进行声明，就可以再block内部进行修改这个变量
    __block int c = 100;
    
    my_sum m_block;// 声明了一个block
    
    m_block = ^(int a, int b) {//定义block,block可以访问外部变量，但是默认情况下不能修改
        
        c = 10;
        return a + b;
    };
    
    NSLog(@"c is %i, a+b is %i,after c is %i",c,m_block(10,11),c);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
//        Button* btn = [[Button alloc] init];
        
        // 定义一个block：返回类型 (^名称) (参数类型列表...) = ^(参数列表...) { 代码块... };
        int (^sum) (int, int) = ^(int a, int b) {
            return a + b;
        };
        
        //block调用方法：方法名称(参数列表...)
        int a  = sum(10,11);
        
        NSLog(@"the sum %i",a);
        
        test();
        
        
        // --------------------------------------------
        Button* btn = [[Button alloc] init];
        
        [btn setM_block:^(Button* btn) {
            NSLog(@"The button-%@ is clicked!",btn);
        }];
        //也可以写成
//        btn.m_block = ^(Button* btn) {
//          // do something...
//        };
        
        [btn click]; //  按钮点击了，就会触发block里面的代码，这种通过事件跳回已经写好的代码的形式叫做：回调。
        
    }
    return 0;
}
