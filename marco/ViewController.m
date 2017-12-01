//
//  ViewController.m
//  marco
//
//  Created by Cain on 2017/11/28.
//  Copyright © 2017年 Goldian. All rights reserved.
//

#import "ViewController.h"
#import "StrengthenMacro.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSMutableArray *marr = [NSMutableArray array];
    
    CGFloat margin = 5;
    
    CGFloat y;
    
    CGFloat height = 20;
    
    for (int i = 0; i < 21; i++) {
        
        y = height * i + margin * (i + 1);
        
        UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, y, 375, height)];
        
        label.text = [NSString stringWithFormat:@"第%d行",i];
        
        label.backgroundColor = [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1];
        
        [marr addObject:label];
        
    }
    
    JK_Prepare_Subviews(self.view, marr[0], marr[1], marr[2], marr[3], marr[4], marr[5] ,marr[6], marr[7], marr[8], marr[9], marr[10], marr[11], marr[12], marr[13], marr[14], marr[15], marr[16], marr[17], marr[18], marr[19]);
}


- (BOOL)prefersStatusBarHidden
{
    return YES;
}

@end

