//
//  SettingsViewController.h
//  DrawPad_ObjC
//
//  Created by SHILEI CUI on 4/30/19.
//  Copyright © 2019 scui5. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SettingsViewControllerDelegate <NSObject>
- (void)closeSettings:(id)sender;
@end

@interface SettingsViewController : UIViewController
@property (weak, nonatomic) IBOutlet UISlider *brushControl;

@property (weak, nonatomic) IBOutlet UISlider *opacityControl;
@property (weak, nonatomic) IBOutlet UIImageView *brushPreview;
@property (weak, nonatomic) IBOutlet UIImageView *opacityPreview;
@property (weak, nonatomic) IBOutlet UILabel *brushValueLabel;
@property (weak, nonatomic) IBOutlet UILabel *opacityValueLabel;
@property (weak, nonatomic) id<SettingsViewControllerDelegate> delegate;
@property (weak, nonatomic) IBOutlet UISlider *redControl;
@property (weak, nonatomic) IBOutlet UISlider *greenControl;
@property (weak, nonatomic) IBOutlet UISlider *blueControl;
@property (weak, nonatomic) IBOutlet UILabel *redLabel;
@property (weak, nonatomic) IBOutlet UILabel *greenLabel;
@property (weak, nonatomic) IBOutlet UILabel *blueLabel;

@property CGFloat brush;
@property CGFloat opacity;
@property CGFloat red;
@property CGFloat green;
@property CGFloat blue;

- (IBAction)closeSettings:(id)sender;
- (IBAction)sliderChanged:(id)sender;


@end
