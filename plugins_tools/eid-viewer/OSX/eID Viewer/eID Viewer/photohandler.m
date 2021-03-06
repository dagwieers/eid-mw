//
//  photohandler.m
//  eID Viewer
//
//  Created by buildslave on 29/04/15.
//  Copyright (c) 2015 Fedict. All rights reserved.
//

#import "photohandler.h"
#import "DataVerifier.h"

@implementation photohandler
- (void)handle_bin_data:(NSData *)data forLabel:(NSString *)label withUi:(AppDelegate *)ui {
    assert([label isEqualToString:@"PHOTO_FILE"] || [label isEqualToString:@"photo"]);
    NSImage* img = [[NSImage alloc] initWithData:data];
    [(NSImageView*)[ui searchObjectById:@"photo" ofClass:[NSImageView class]] setImage:img];
    [[DataVerifier verifier]handle_bin_data:data forLabel:label withUi:ui];
}
@end
