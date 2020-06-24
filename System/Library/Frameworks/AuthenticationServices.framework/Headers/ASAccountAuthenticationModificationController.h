//
//  ASAccountAuthenticationModificationController.h
//  AuthenticationServices Framework
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <AuthenticationServices/ASFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ASAccountAuthenticationModificationController;
@class ASAccountAuthenticationModificationRequest;

AS_EXTERN API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst, tvos, watchos)
@protocol ASAccountAuthenticationModificationControllerDelegate <NSObject>

@optional
- (void)accountAuthenticationModificationController:(ASAccountAuthenticationModificationController *)controller didSuccessfullyCompleteRequest:(ASAccountAuthenticationModificationRequest *)request withUserInfo:(nullable NSDictionary *)userInfo NS_SWIFT_NAME(accountAuthenticationModificationController(_:didSuccessfullyComplete:userInfo:));
- (void)accountAuthenticationModificationController:(ASAccountAuthenticationModificationController *)controller didFailRequest:(ASAccountAuthenticationModificationRequest *)request withError:(NSError *)error NS_SWIFT_NAME(accountAuthenticationModificationController(_:didFail:error:));

@end

AS_EXTERN API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst, tvos, watchos)
@protocol ASAccountAuthenticationModificationControllerPresentationContextProviding <NSObject>
@required

#if !TARGET_OS_WATCH
/*! @abstract Return a view anchor that is most appropriate for authorization UI to be presented over.
 */
- (ASPresentationAnchor)presentationAnchorForAccountAuthenticationModificationController:(ASAccountAuthenticationModificationController *)controller;
#endif

@end

AS_EXTERN API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst, tvos, watchos)
@interface ASAccountAuthenticationModificationController : NSObject

@property (nonatomic, weak, nullable) id <ASAccountAuthenticationModificationControllerDelegate> delegate;

@property (nonatomic, weak, nullable) id <ASAccountAuthenticationModificationControllerPresentationContextProviding> presentationContextProvider;

- (void)performRequest:(ASAccountAuthenticationModificationRequest *)request;

@end

NS_ASSUME_NONNULL_END
