//
//  ImageViewController.m
//  DrawPad_ObjC
//
//  Created by SHILEI CUI on 4/30/19.
//  Copyright © 2019 scui5. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ImageViewController.h"
#import "ImageCollectionViewCell.h"
@import Firebase;

@interface ImageViewController()
@property (weak, nonatomic) IBOutlet UICollectionView *colView;
@property (strong, nonatomic) NSArray *imagesArray;
@property (strong, nonatomic) FIRDatabaseReference *ref;

@end

@implementation ImageViewController

- (void)viewDidLoad{
    NSMutableArray * imagesArray = [[NSMutableArray alloc] init];
    
}

- (void)viewWillAppear:(BOOL)animated{
    [self.colView reloadData];
}

- (nonnull __kindof UICollectionViewCell *)collectionView:(nonnull UICollectionView *)collectionView cellForItemAtIndexPath:(nonnull NSIndexPath *)indexPath {
    ImageCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"Cell" forIndexPath:indexPath];
    
    self.ref = [[FIRDatabase database] reference];
    [self.ref observeEventType:FIRDataEventTypeValue withBlock:^(FIRDataSnapshot * _Nonnull snapshot) {
        NSDictionary *usersDict = snapshot.value;
        NSDictionary *userDict1 = [usersDict objectForKey:@"userImages"];
        //sorting array using descriptor
        NSSortDescriptor *sortDescriptor;
        sortDescriptor = [[NSSortDescriptor alloc] initWithKey:@"imageOrder"
                                                     ascending:YES];
        NSArray *sortedArray = [userDict1.allValues sortedArrayUsingDescriptors:@[sortDescriptor]];
        
        self.imagesArray = sortedArray;
        //NSLog(@"Information : %@",self.imagesArray);
        NSString *stringURL = [[self.imagesArray objectAtIndex:indexPath.row] objectForKey:@"imageURL"];
        
        dispatch_async(dispatch_get_global_queue(0,0), ^{
            NSData * data = [[NSData alloc] initWithContentsOfURL: [NSURL URLWithString: stringURL]];
            if ( data == nil )
                return;
            dispatch_async(dispatch_get_main_queue(), ^{
                cell.drawPadImgView.image = [UIImage imageWithData: data];
            });
        });
        
        NSLog(@"%@",stringURL);
    }];
    
    
    return cell;
}

- (NSInteger)collectionView:(nonnull UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    //return [self.imagesArray count];
    if (self.imagesArray.count != 0){
        return [self.imagesArray count];
    }else{
        return 1;
    }
    
}





@end
