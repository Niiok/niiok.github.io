---
title: "Cpp Naming rule"
author: "Niiok"
categories: ["C++"]
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


## File name
- **fully lower-case**
- word separation expressed as `_` (underscore)
    
```
file_name.txt    
very_good_source_code.c
```


## Type name
- start with capital letter
- next letters are lower-case
- word separation expressed as upper-cased first letter
    
```C++
class SuperDuperClass{};
struct TypeNameExpressedLikeThis{};
```


## Variable name
- function parameters are included in variable
- Common variable name
  - **fully lower-case**
  - space expressed into `_` (underscore)
      
  ```C++ 
  int integer_variable = 4;    
  int quantity_of_cookies = 0;       
  ```
        
- Class data member name
  - **same with common variable name**, but **has tailing `_` (underscore)**
      
  ```C++
  class SampleClass    
  {    
  private:   
      int class_member_;    
      float x_, y_;    
  }; 
  ```
        
- Struct data member name 
  - **fully same with common variable name**
      
  ```C++
  struct SampleStruct    
  {
      int struct_member;    
      float x, y;    
  };    
  ```
        

## Constant name
- start with `k`
- word separation expressed as upper-cased first letter
- if you can't use uppercase spacing, `_` (underscore) is allowed that time
    
```C++
const int kMagicNumber = 42;    
const int kAndroid8_0_0 = 24;    
```


## Function name
- start with capital letter
- word separation expressed as upper-cased first letter
- some functions like accessors and mutators can be named like variable.
    
```C++
MoveToThere();
ScoreCount();
get_name();
set_name();
size();
```


## NameSpace name
- **fully lower-case**
- word separation expressed as `_` (underscore)

```C++
namespace countryside_bus {}
namespace project_goo {}
```


## Enumerator name
- enum follows Constant naming rule
- not Macro naming rule

```C++
enum Fruits {
    kBanana,
    kApple,
    kCherry
};
```


## Macro name
- fully CAPITAL LETTER
- word separation expressed as `_` (underscore)

```C++
#define PI 3.14
#define ARRAY_SIZE 32
```


## Some Exceptions
If you are naming something that is analogous to an existing C or C++ entity then you can follow the existing naming convention scheme.    

- bigopen()
  - function name, follows form of open()
- uint
  - typedef
- bigpos
  - struct or class, follows form of pos
- sparse_hash_map
  - STL-like entity; follows STL naming conventions
- LONGLONG_MAX
  - a constant, as in INT_MAX


