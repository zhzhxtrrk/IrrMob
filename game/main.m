//
//  main.m
//  IrrMob
//
//  Created by Zhe Zhang on 12/13/11.
//  Copyright (c) 2011 moqikaka.com. All rights reserved.
//

#ifndef IrrMob_main_m
#define IrrMob_main_m

#import "UIKit/UIKit.h"
#import "GLKit/GLKit.h"

void initGame(void* window, int w, int h);
void updateFrame();
void touchEvent(int type, int x, int y);

int main(int argc, char** argv)
{
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, @"AppDelegate");
    }
}

@interface GLViewController : GLKViewController {

}
@end

@implementation GLViewController

-(void) update
{
    updateFrame();
}

-(void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

-(void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

-(void) touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

-(void) touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

@end

@interface AppDelegate : NSObject<UIApplicationDelegate> {
    
}
@end

@implementation AppDelegate

-(void) applicationDidFinishLaunching:(UIApplication *)application
{
    CGRect rect = [[UIScreen mainScreen] bounds];
    UIWindow* window = [[UIWindow alloc] initWithFrame:rect];
    [window makeKeyAndVisible];
    
    initGame(window, rect.size.width, rect.size.height);
    
    [window setRootViewController: [[GLViewController alloc] init]];
}

@end

#endif
