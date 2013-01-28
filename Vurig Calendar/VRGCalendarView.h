//
//  VRGCalendarView.h
//  Vurig
//
//  Created by in 't Veen Tjeerd on 5/8/12.
//  Copyright (c) 2012 Vurig Media. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "UIColor+expanded.h"

#define kVRGCalendarViewTopBarHeight 60
#define kVRGCalendarViewWidth 320

#define kVRGCalendarViewDayWidth 44
#define kVRGCalendarViewDayHeight 44

#define kVRGCalendarTextColor @"0x383838"
#define kVRGCalendarArrowColor @"0x000000"
#define kVRGCalendarBackgroundColor @"0xFFFFFF"
#define kVRGCalendarPrevOrNextTextColor @"0x767676"
#define kVRGCalendarSelectedTextBackgroundColor @"0x006dbc"
#define kVRGCalendarSelectedTextColor @"0xFFFFFF"
#define kVRGCalendarDisableTextColor @"0xDCDCDC"
#define kVRGCalendarGridBackgroundColor @"0xf3f3f3"
#define kVRGCalendarGridDarkLinesColor @"0xcfd4d8"


@protocol VRGCalendarViewDelegate;
@interface VRGCalendarView : UIView {
//    id <VRGCalendarViewDelegate> delegate;
    
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

@property (nonatomic, assign) id <VRGCalendarViewDelegate> delegate;
@property (nonatomic, retain) NSDate *currentMonth;
@property (nonatomic, retain) NSDate *beginDate;
@property (nonatomic, retain) NSDate *endDate;
@property (nonatomic, retain) UILabel *labelCurrentMonth;
@property (nonatomic, retain) UIImageView *animationView_A;
@property (nonatomic, retain) UIImageView *animationView_B;
@property (nonatomic, retain) NSArray *markedDates;
@property (nonatomic, retain) NSArray *markedColors;
@property (nonatomic, getter = calendarHeight) float calendarHeight;
@property (nonatomic, retain, getter = selectedDate) NSDate *selectedDate;

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
