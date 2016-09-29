# appodeal-monkey-x-ios-plugin

To add Appodeal ads to your project you should download this plugin and add folder "appodeal" to your project folder "modules".

After that you should build your project in Ted SDK to convert your app to XCode project.
If you see error like this: 
```
MonkeyXPro78h/modules/appodeal/appodeal_example.buildv78h/ios/main.mm:4290:9: fatal error: 'Appodeal/Appodeal.h' file not found
#import "Appodeal/Appodeal.h"
```
Don't worry, we will fix that later.

After building open generated XCode project and make some changes:

1. Type bundle identifier, type current version of app, and choose Provisioning profile for successful debug.
https://i.gyazo.com/820f0f6d620f1ff4c73c50a7e6ead7de.png

2. Disable bitcode in Build Settings -> Build Options.
https://i.gyazo.com/8a503546a1502d216fd6bcad3c31413a.png

3. Add "Allow arbitrary loads" subproperty in "App Transport Security" property and set it to YES
https://i.gyazo.com/d9914758eb9e9f2fe181e743b6449f7a.png

4. Change deployment target in project settings and target setting to 8.1 or higher.
https://i.gyazo.com/34945a9fe4eb50e0921b22a2a8344be9.png
https://i.gyazo.com/9421a8230374a6fae563ff87f0e28389.png

5. Add following libraries to build phases.
https://i.gyazo.com/ef7094ed523f836a2d74c63da725a8b9.png

6. Add "Appodeal.framework" and "Appodeal.bundle" to framework folder in your project. 
First, download Appodeal SDK from here: http://bit.ly/appodeal-ios-sdk-1-2-4
After downloading unpach archive and simply drag and drop framework and bundle to your project. Doing this you should check "Copy items if needed" option.
This SDK needs some adapters to work with. Each adapter is responsible for showing ads from its ad network.
You can download all adapters from here: https://github.com/appodeal/appodeal-ios-sdk-mobile-adapters
Unpack archive and drag and drop adapters that you need to your project.
After this your project tree in XCode should be like this one:
https://i.gyazo.com/a9bacea9c230e03830f839a71fd69268.png

All done, now you can launch your project.
