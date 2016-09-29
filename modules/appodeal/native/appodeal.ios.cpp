#import "Appodeal/Appodeal.h"

const int INTERSTITIAL  			= 1;
const int SKIPPABLE_VIDEO      		= 2;
const int BANNER        			= 4;
const int BANNER_BOTTOM 			= 8;
const int BANNER_TOP    			= 16;
const int REWARDED_VIDEO       		= 128;
const int NON_SKIPPABLE_VIDEO  		= 256;

void showAlert(NSString* message)
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Testing alert"
                                                    message:message
                                                   delegate:nil
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles:nil];
    [alert show];
}

int nativeAdTypesForType(int adTypes) {
    int nativeAdTypes = 0;

    if ((adTypes & INTERSTITIAL) > 0) {
        nativeAdTypes |= AppodealAdTypeInterstitial;
    }

    if ((adTypes & SKIPPABLE_VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeSkippableVideo;
    }
    
    if ((adTypes & NON_SKIPPABLE_VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeNonSkippableVideo;
    }
    
    if ((adTypes & REWARDED_VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeRewardedVideo;
    }

    if ((adTypes & BANNER) > 0 ||
        (adTypes & BANNER_TOP) > 0 ||
        (adTypes & BANNER_BOTTOM) > 0) {

        nativeAdTypes |= AppodealAdTypeBanner;
    }

    return nativeAdTypes;
}

int nativeShowStyleForType(int adTypes) {
    bool isInterstitial = (adTypes & INTERSTITIAL) > 0;
    bool isVideo = (adTypes & SKIPPABLE_VIDEO) > 0;

    
    if (isInterstitial && isVideo) {
        return AppodealShowStyleVideoOrInterstitial;
    } else if (isVideo) {
        return AppodealAdTypeSkippableVideo;
    } else if (isInterstitial) {
        return AppodealShowStyleInterstitial;
    }

    if ((adTypes & BANNER_TOP) > 0) {
        return AppodealShowStyleBannerTop;
    }

    if ((adTypes & BANNER_BOTTOM) > 0) {
        return AppodealShowStyleBannerBottom;
    }
    
    if ((adTypes & SKIPPABLE_VIDEO) > 0) {
        return AppodealShowStyleSkippableVideo;
    }
    
    if ((adTypes & NON_SKIPPABLE_VIDEO) > 0) {
        return AppodealShowStyleNonSkippableVideo;
    }

    if ((adTypes & REWARDED_VIDEO) > 0) {
        return AppodealShowStyleRewardedVideo;
    }

    return 0;
}
/*
//delegate glue
@interface AppodealDelegateGlue : NSObject <AppodealSkippableVideoDelegate> {}

- (void)videoDidLoadAd;
- (void)videoDidFailToLoadAd;
- (void)videoDidPresent;
- (void)videoWillDismiss;
- (void)videoDidFinish;

@end
*/
class BBAppodeal{

    static BBAppodeal *_appodeal;

public:

    BBAppodeal();

    static BBAppodeal *GetAppodeal();
    /*
    virtual void videoDidLoadAd();
    virtual void videoDidFailToLoadAd();
    virtual void videoDidPresent();
    virtual void videoWillDismiss();
    virtual void videoDidFinish();
    */
    void initialize(String _id, int adType);
    bool show(int adType);
    void hide(int adType);
    void setAutoCache(int adType, bool state);
    void disableLocationPermissionCheck();
    void setSmartBannersEnabled(bool state);
    void setBannerBackgroundVisible(bool state);
    void setBannerAnimationEnabled(bool state);
    void confirm(int adType);
    void setUserId(String _userid);

};

/*
//delegate glue
@implementation AppodealDelegateGlue

- (void)videoDidLoadAd
{
    NSLog(@"video ad did load");
    BBAppodeal::_appodeal->videoDidLoadAd();
}

- (void)videoDidFailToLoadAd
{
    NSLog(@"video ad failed to load");
    BBAppodeal::_appodeal->videoDidFailToLoadAd();
}

- (void)videoDidPresent
{
    NSLog(@"video ad did present");
    BBAppodeal::_appodeal->videoDidPresent();
}

- (void)videoWillDismiss
{
    NSLog(@"video ad has been closed or dismissed");
    BBAppodeal::_appodeal->videoWillDismiss();
}

- (void)videoDidFinish
{
    NSLog(@"video ad has been finished and user should be rewarded");
    BBAppodeal::_appodeal->videoDidFinish();
}

@end
*/

BBAppodeal *BBAppodeal::_appodeal;

BBAppodeal::BBAppodeal() {
}

BBAppodeal *BBAppodeal::GetAppodeal() {
    if( !_appodeal ) _appodeal=new BBAppodeal();
   // [Appodeal setSkippableVideoDelegate:[[AppodealDelegateGlue alloc] init]];
    return _appodeal;
}

/*
void BBAppodeal::videoDidLoadAd()
{
}

void BBAppodeal::videoDidFailToLoadAd()
{
}

void BBAppodeal::videoDidPresent()
{
}

void BBAppodeal::videoWillDismiss()
{
}

void BBAppodeal::videoDidFinish()
{
}

*/

void BBAppodeal::initialize(String _id, int adType) {
    NSString* appID = _id.ToNSString();
    [Appodeal initializeWithApiKey:appID types:nativeAdTypesForType(adType)];
}

void BBAppodeal::confirm(int adType) {
    return [Appodeal confirmUsage:nativeShowStyleForType(adType)];
}

void BBAppodeal::hide(int adType) {
    [Appodeal hideBanner];
}

bool BBAppodeal::show(int adType) {
    /*BBMonkeyAppDelegate *appDelegate=(BBMonkeyAppDelegate*)[[UIApplication sharedApplication] delegate];
    return [Appodeal showAd:nativeShowStyleForType(adType) rootViewController:appDelegate->viewController];*/
    return [Appodeal showAd:nativeShowStyleForType(adType) rootViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
    
}

void BBAppodeal::setAutoCache(int adType, bool state) {
    [Appodeal setAutocache:state types:nativeAdTypesForType(adType)];
}

void BBAppodeal::setSmartBannersEnabled(bool state) {
    [Appodeal setSmartBannersEnabled:state];
}

void BBAppodeal::setBannerBackgroundVisible(bool state) {
    [Appodeal setBannerBackgroundVisible:state];
}

void BBAppodeal::setBannerAnimationEnabled(bool state) {
    [Appodeal setBannerAnimationEnabled:state];
}
void BBAppodeal::disableLocationPermissionCheck() {
    [Appodeal disableLocationPermissionCheck];
}
void BBAppodeal::setUserId(String _userid) {
      [Appodeal setUserId:_userid.ToNSString()];
}
//void
