/* 
 * Copyright (c) 2011, salesforce.com, inc.
 * Author: Jonathan Hersh jhersh@salesforce.com
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided 
 * that the following conditions are met:
 * 
 *    Redistributions of source code must retain the above copyright notice, this list of conditions and the 
 *    following disclaimer.
 *  
 *    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and 
 *    the following disclaimer in the documentation and/or other materials provided with the distribution. 
 *    
 *    Neither the name of salesforce.com, inc. nor the names of its contributors may be used to endorse or 
 *    promote products derived from this software without specific prior written permission.
 *  
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import <UIKit/UIKit.h>

@protocol DateTimePickerDelegate;

@interface DateTimePicker : UIViewController {}

@property (nonatomic, assign) id <DateTimePickerDelegate> dateTimeDelegate;
@property (nonatomic, assign) BOOL allowsClearingFieldValue;

@property (nonatomic, retain) UIDatePicker *picker;

+ (DateTimePicker *) dateTimePicker;

- (void) setDatePickerDate:(NSDate *)date;
- (void) setDatePickerMode:(UIDatePickerMode)mode;
- (void) setDateTimePickerTitle:(NSString *)title;

// working around the world's most idiotic bug
// http://omegadelta.net/2010/06/04/ipad-simulator-crashes-if-a-uidatepicker-is-in-a-uipopovercontroller/
- (void) setDatePickerView;
- (void) unsetDatePickerView;

@end

// START:Delegate
@protocol DateTimePickerDelegate <NSObject>

@optional

- (void) dateTimePicker:(DateTimePicker *)picker didChangeToDate:(NSDate *)date;
- (void) dateTimePickerDidClearFieldValue:(DateTimePicker *)picker;

@end
// END:Delegate