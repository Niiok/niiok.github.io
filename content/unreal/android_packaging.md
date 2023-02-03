---
title: "Android packaging"
author: "Niiok"
categories: ["Unreal"]
date: 2022-03-14T13:07:15+09:00
weight: 1


# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---

## To package apk successfully via Android Studio (UE4.25~)
- [First, follow this official document.](https://docs.unrealengine.com/SharingAndReleasing/Mobile/Android/Setup/AndroidStudio/)
- Tips below may be useful if your Gradle spit errors out. (wrote in 2022 March with UE4.27.2)
  - Check existence of these 2 files (Windows)
    - `Users/[User name]/AppData\Local\Android\Sdk\build-tools\[SDK version]/dx.bat`
    - `Users/[User name]/AppData\Local\Android\Sdk\build-tools\[SDK version]/lib/dx.jar`
  - If they don't exist, make symbolic links of `d8.bat` and `d8.jar`.
  - You MUST enable `AndroidDeviceProfileSelector` and `AndroidPermission` plugins.
  - Then execute `[EngineFolder]/Engine/Extras/Android/SetupAndroid.*` while UE4 and Android Studio are off.
  - UE4 does not support `Android SDK Command-line tools` **v9.0** or more, so make sure to download **v8.0** and set folder name `8.0` to `latest`.