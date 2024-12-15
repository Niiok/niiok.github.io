---
title: "Unreal basic"
author: "Niiok"
categories: ["Unreal"]
date: 1970-01-01T00:00:00+00:00
weight: 1


# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---


## Unreal project
If you want to study the API on your own; You should use that API as a user until you get used to it and read the header files.    
In every unreal code, they include "CoreMinimal.h" or "EngineMinimal.h" and those header files will be key to start studying.    

### Project hierarchy
- Config :    
    project setting values. NEEDED-do not remove    
- Content :    
    asset storage. NEEDED-do not remove    
- Intermediate :    
    intermediate files. Recovered after remove
- Saved :    
    save files, screenshots and etc. Not recovered after remove    

- Binaries (C++) :    
    binary files created after compile. Recovered after remove    
- Source (C++) :    
    source files. NEEDED-do not remove    
	If your project got something wrong and doesn't work, remove unnecessary files(files in .gitignore) and execute .uproject file.    
	If your project isn't getting better and it's clear UnreealEngine is preserving integrity, import proper Config files from new project to current project's Config folder. (you need to change project name of files to adjust config.)    


### Type name prefix
- A	:    classes inherited AActor; Actors
- U	:    classes inherited UObject; non-actor unreal objects
- S	:    classes inherited SWidget; Widgets
- E	:    Enum
- I	:    Interface
- T	:    Template
- F	:    Others
- b	:    boolean variables; not class, only variable

Type name and variable name are noun.    
Funtion name and method name are verb that describe their effct or return value(if it doesnt have effect.)    


## UObject
every classes in UE4 derived from `UObject`.    
Subclasses that not inherited from `AActor` generally called as UObject in documents.

## Actor
Actors are objects in world that consist game.    
Every actor is derived from `AActor`.    


## Component
Components are subobject(not subclass) of Actors that endow functions with Actor.    
Every component is derived from `UActorComponent`.    

	Actor    
	├── Input    
	├── Movement    
	│   ├── NavMovement    
	│   │   ├── PawnMovement    
	│   │   │   ├── CharacterMovement    
	│   │   │   └── ...    
	│   │   └── ...    
	│   └── ...    
	├── Scene
	│   ├── Camera    
	│   ├── SpringArm    
	│   ├── Primitive    
	│   │   ├── Mesh    
	│   │   │   ├── Widget    
	│   │   │   ├── StaticMesh    
	│   │   │   │   └── ...    
	│   │   │   ├── SkinnedMesh    
	│   │   │   │   ├── SkeletalMesh    
	│   │   │   │   │   └── ...    
	│   │   │   │   └── ...    
	│   │   │   └── ...    
	│   │   ├── Shape    
	│   │   │   ├── Capsule    
	│   │   │   └── ...    
	│   │   └── ...    
	│   └── ...    
	└── ...    

