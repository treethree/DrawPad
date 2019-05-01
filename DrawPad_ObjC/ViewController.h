//
//  ViewController.h
//  DrawPad_ObjC
//
//  Created by SHILEI CUI on 4/30/19.
//  Copyright © 2019 scui5. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Social/Social.h"
#import "SettingsViewController.h"
#import <MessageUI/MessageUI.h>
#import <MessageUI/MFMailComposeViewController.h>

@interface ViewController : UIViewController<UIActionSheetDelegate, MFMailComposeViewControllerDelegate> {
    
    SLComposeViewController *mySLComposeSheet;
    
    CGPoint lastPoint;
    CGFloat red;
    CGFloat green;
    CGFloat blue;
    CGFloat brush;
    CGFloat opacity;
    BOOL mouseSwiped;
}

@property(nonatomic,strong)MFMailComposeViewController *emailDialog;
@property (weak, nonatomic) IBOutlet UIImageView *mainImage;
@property (weak, nonatomic) IBOutlet UIImageView *tempDrawImage;

- (IBAction)pencilPressed:(id)sender;
- (IBAction)eraserPressed:(id)sender;
- (IBAction)reset:(id)sender;
- (IBAction)settings:(id)sender;
- (IBAction)save:(id)sender;
- (IBAction)uploadImg:(id)sender;

@end

