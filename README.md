# appodeal-monkey-x-ios-plugin

To add Appodeal ads to your project you should download this plugin and add folder "appodeal" to your project folder "modules".

After that you should build your project in Ted SDK to convert your app to XCode project.
If you see error like this: 
```
MonkeyXPro78h/modules/appodeal/appodeal_example.buildv78h/ios/main.mm:4290:9: fatal error: 'Appodeal/Appodeal.h' file not found
#import "Appodeal/Appodeal.h"
```
don't worry, we will fix that later.

After converting you should open generated XCode project and make some changes:

1. Type bundle identifier, current version of app and choose Provisioning profile for successful debug.
![Alt text](https://i.gyazo.com/820f0f6d620f1ff4c73c50a7e6ead7de.png)

2. Disable bitcode in Build Settings -> Build Options of your project.
![Alt text](https://i.gyazo.com/8a503546a1502d216fd6bcad3c31413a.png)

3. Set up the following keys in your app’s info.plist:

```
<key>NSAppTransportSecurity</key>
<dict>
  <key>NSAllowsArbitraryLoads</key>
  <true/>
</dict>
```

Add this key in Info.plist , if you use this function in your app

```
<key>NSBluetoothPeripheralUsageDescription</key>
<string>Advertising</string>
<key>NSCalendarsUsageDescription</key>
<string>Advertising</string>
<key>NSLocationWhenInUseUsageDescription</key>
<string>Advertising</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>Advertising</string>
```

4. Change deployment target in project settings and target settings to 8.1 or higher.

5. Add "libz.tbd", "libc++.tbd", "libsqlite3.tbd", "libxml2.2" libraries to Build phases->Link Binary With Libraries.
![Alt text](http://i.imgur.com/GQc4oX5.png)

6. Add "Appodeal.framework" and "Appodeal.bundle" to folder "frameworks" in your project.
First, download Appodeal SDK from here: http://bit.ly/ios-sdk-1-3-9
After downloading unzip archive. Renamed the "Resources" folder in unzipped files to "Appodeal.bundle" then drag and drop framework and Resources to your project. Doing this you should check "Copy items if needed" option.
![Alt text](http://i.imgur.com/v6lc5Hq.png)
![Alt text](http://i.imgur.com/M7Viy7F.png)

All done, now you can launch your project in XCode.
