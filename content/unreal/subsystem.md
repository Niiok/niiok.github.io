---
title: "Unreal Subsystem"
author: "Niiok"
categories: ["Unreal"]
date: 2022-03-17T23:42:05+09:00
#draft: true
weight: 1


# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---

## Intro
- Subsystem is handy and useful instance with various lifecycle.
- Every Subsystems declared as class will be instanced and called `Inintialize()` and `Deinitialize()` in proper time.
- Thanks to Subsystems, GameInstance don't have to be over-responsible. (and other massive advantages)


## Subsystem variety
- UEngineSubsystem
  - Lifetime : `StartUp()` ~ `ShutDown()`
  - Reference : `GEngine->GetEngineSubsystem<T>();`

- UEditorSubsystem
  - Lifetime : `StartUp()` ~ `ShutDown()`
  - Reference : `GEditor->GetEditorSubsystem<T>();`
  
- UGameInstanceSubsystem
  - Lifetime : Same with GameInstance
  - Reference : `[GameInstance]->GetSubsystem<T>();`

- ULocalPlayerSubsystem
  - Lifetime : Same with LocalPlayer
  - Reference : `[LocalPlayer]->GetSubsystem<T>();`


## Online Subsystem?