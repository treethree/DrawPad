//
//  LocationService.h
//  DrawPad_ObjC
//
//  Created by SHILEI CUI on 5/1/19.
//  Copyright © 2019 scui5. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface LocationService : NSObject <CLLocationManagerDelegate>

+(LocationService *) sharedInstance;

@property (strong, nonatomic) CLLocationManager *locationManager;
@property (strong, nonatomic) CLLocation *currentLocation;
@property (strong, nonatomic) CLGeocoder *geocoder;

- (void)startUpdatingLocation;

@end

