//
//  PAPasscodeViewController.h
//  PAPasscode
//
//  Created by Denis Hennessy on 15/10/2012.
//  Copyright (c) 2012 Peer Assembly. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PasscodeActionSet,
    PasscodeActionEnter,
    PasscodeActionChange
} PasscodeAction;

@class PAPasscodeViewController;

@protocol PAPasscodeViewControllerDelegate <NSObject>

@optional

- (void)PAPasscodeViewControllerDidCancel:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidChangePasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidEnterAlternativePasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidEnterPasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidSetPasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewController:(PAPasscodeViewController *)controller didFailToEnterPasscode:(NSInteger)attempts;

@end

@interface PAPasscodeViewController : UIViewController {
    UIView *contentView;
    NSInteger phase;
    UILabel *promptLabel;
    UILabel *messageLabel;
    UIImageView *failedImageView;
    UILabel *failedAttemptsLabel;
    UITextField *passcodeTextField;
    UIImageView *digitImageViews[4];
    UIImageView *snapshotImageView;
}

@property (nonatomic, strong) UIView *backgroundView;
@property (nonatomic, assign, readonly) PasscodeAction action;
@property (nonatomic, weak) id<PAPasscodeViewControllerDelegate> delegate;
@property (nonatomic, copy) NSString *alternativePasscode;
@property (nonatomic, copy) NSString *passcode;
@property (nonatomic, assign) BOOL simple;
@property (nonatomic, assign) NSUInteger failedAttempts;
@property (nonatomic, copy) NSString *enterPrompt;
@property (nonatomic, copy) NSString *confirmPrompt;
@property (nonatomic, copy) NSString *changePrompt;
@property (nonatomic, copy) NSString *message;

- (id)initForAction:(PasscodeAction)action;

@end
