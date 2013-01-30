//
//  VRGCalendarView.h
//  Vurig
//
//  Created by in 't Veen Tjeerd on 5/8/12.
//  Copyright (c) 2012 Vurig Media. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIColor+expanded.h"

#define kVRGCalendarViewTopBarHeight    70
#define kVRGCalendarViewTitleHeight     50
#define kVRGCalendarViewWidth          320

#define kVRGCalendarViewDayWidth        44
#define kVRGCalendarViewDayHeight       44

#define kVRGCalendarTextColor                   @"0x000000"
#define kVRGCalendarArrowColor                  @"0x000000"
#define kVRGCalendarBackgroundColor             @"0xFFFFFF"
#define kVRGCalendarPrevOrNextTextColor         @"0x767676"
#define kVRGCalendarSelectedTextBackgroundColor @"0xFF8000"
#define kVRGCalendarSelectedTextColor           @"0xFFFFFF"
#define kVRGCalendarTodayBackgroundColor        @"0xEEEEEE"
#define kVRGCalendarTodayTextColor              @"0x383838"
#define kVRGCalendarDisableTextColor            @"0xDCDCDC"
#define kVRGCalendarGridBackgroundColor         @"0xFFFFFF"
#define kVRGCalendarGridDarkLinesColor          @"0xFFFFFF"
#define kVRGCalendarDayLabelColor               @"0x919191"
#define kVRGCalendarTitleLabelColor             @"0x5E5E5E"

#define kKNCalendarTitleFont          [UIFont fontWithName:@"HelveticaNeue" size:22]
#define kKNCalendarNumberFont         [UIFont fontWithName:@"HelveticaNeue" size:22]
#define kKNCalendarDayLabelFont       [UIFont fontWithName:@"HelveticaNeue-Bold" size:13]

#define kKNCalendarArrowHeight        18
#define kKNCalendarArrowOffsetTop     14
#define kKNCalendarArrowOffsetSide    18

@protocol VRGCalendarViewDelegate;
@interface VRGCalendarView : UIView {

    NSDate *currentMonth;
    NSDate *beginDate;
    NSDate *endDate;

    UILabel *labelCurrentMonth;

    BOOL isAnimating;
    BOOL prepAnimationPreviousMonth;
    BOOL prepAnimationNextMonth;

    UIImageView *animationView_A;
    UIImageView *animationView_B;

    NSArray *markedDates;
    NSArray *markedColors;
}

@property (nonatomic, weak) id <VRGCalendarViewDelegate> delegate;
@property (nonatomic, strong) NSDate *currentMonth;
@property (nonatomic, strong) NSDate *beginDate;
@property (nonatomic, strong) NSDate *endDate;
@property (nonatomic, strong) UILabel *labelCurrentMonth;
@property (nonatomic, strong) UIImageView *animationView_A;
@property (nonatomic, strong) UIImageView *animationView_B;
@property (nonatomic, strong) NSArray *markedDates;
@property (nonatomic, strong) NSArray *markedColors;
@property (nonatomic, getter = calendarHeight) float calendarHeight;
@property (nonatomic, strong, getter = selectedDate) NSDate *selectedDate;

-(void)selectDate:(int)date;
-(void)reset;

-(void)markDates:(NSArray *)dates;
-(void)markDates:(NSArray *)dates withColors:(NSArray *)colors;

-(void)showNextMonth;
-(void)showPreviousMonth;

-(int)numRows;
-(void)updateSize;
-(UIImage *)drawCurrentState;

@end

@protocol VRGCalendarViewDelegate <NSObject>
-(void)calendarView:(VRGCalendarView *)calendarView switchedToMonth:(int)month targetHeight:(float)targetHeight animated:(BOOL)animated;
-(void)calendarView:(VRGCalendarView *)calendarView dateSelected:(NSDate *)date;
@end
