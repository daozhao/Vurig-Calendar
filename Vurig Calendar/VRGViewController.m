//
//  VRGViewController.m
//  Vurig Calendar
//
//  Created by in 't Veen Tjeerd on 5/29/12.
//  Copyright (c) 2012 Vurig. All rights reserved.
//

#import "VRGViewController.h"

@implementation VRGViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Setup calendar with delegate and date range
    VRGCalendarView *calendar = [[VRGCalendarView alloc] init];
    calendar.delegate=self;
    calendar.beginDate = [NSDate dateWithTimeIntervalSinceNow: -(60*60)*24*8];
    calendar.endDate = [NSDate dateWithTimeIntervalSinceNow:(60*60)*24*40];
    [self.view addSubview:calendar];
}

-(void)calendarView:(VRGCalendarView *)calendarView switchedToMonth:(int)month targetHeight:(float)targetHeight animated:(BOOL)animated {

    // Mark (underline) dates
    if (month==[[NSDate date] month]) {
        [calendarView markDates: @[@(1), @(5)]];
    }

    // Demo select date
    [calendarView selectDate:3];
}

-(void)calendarView:(VRGCalendarView *)calendarView dateSelected:(NSDate *)date {
    // Demo callback
    NSLog(@"Selected date = %@",date);
}

@end
