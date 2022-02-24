---
title: "Intro"
author: "Niiok"
categories: ["C"]
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

# Introduction
    
<!--current page 15-->
    
## Writer prefer 1983 ANSI C (K&R 2nd).
    
- C was born for UNIX
  - C is machine independent
  - C is simple and concise (even though program with it is complicated)
  
- Creator's words
  - > C is a general-purpose programming language which features economy of expression, modern control flow and data structures, and a rich set of operators.    
  - > C wears well as one's experience with it grows.    
  - > C is a relatively "low level" language.    
    
- standard library
  - input output
  - memory management
  - string manipulation
  - etc

- What C provides
  - data types
    - characters
    - integers
    - floating point numbers
    - and hierarchy of derived data types created with pointers, arrays, structures, and unions
  - expressions are formed from operators and operands
    - any expression, including an assignment or a function call, cam be statement
  - pointers provide for machine-independent address arithmetic
  - control-flow
    - statement grouping
    - decision making (if-else)
    - selecting one of a set of possible cases (switch)
    - looping 
      - with the termination test at the top (while, for)
      - with the termination test at the bottom (do)
      - early loop exit (break)
      - early loop skip (continue)
  - Function
    - returns data type
    - may be called recursively
    - may exist in separated source files that are compiled separately
  - Variables
    - declared autoatically
    - may be declared in block-structure
    - may be internal to function, external but known only within source files, and conditional compilation
  - C is a relatively "low level" language
    - deals with characters, numbers, and addresses
    - there are no operations that manipulate an entire array or string
      - although structures may be copied as a unit
    - stirage allocation facility
      - static definition
      - stack discipline provided by the local variables of functions
      - there is no heap or garbage collection (?)
  - Input / Output
    - C itself provides no input/output facilities
      - no READ, WRITE statement
      - no built-in file access methods
    - input/output provided by explicitly-called functions
  - C supports only single-thread control flow (?)
    - tests, loops, grouping, subprograms
    - no multiprogramming 





