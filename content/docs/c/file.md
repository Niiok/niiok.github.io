---
title: "File"
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

- FILE    
  

- fopen
```C
FILE* fopen (char* name, char* mode);
```
used to openning file with file name _`name`_.
- _`mode`_
  - "r" : read
  - "w" : write (will be overwrited), (make new file if it doesn't exist and possible)
  - "a" : append (make new file if it doesn't exist and possible)
  - "rb" : binary-read
  - "wb" : binary-write (will be overwrited), (make new file if it doesn't exist and possible)
  - "ab" : binary-append (make new file if it doesn't exist and possible)

- getc
```C
int getc (FILE* fp);
```

- putc
```C
int putc (int c, FILE* fp);
```

- getchar
```C
#define  getchar()  getc( stdin )
```

- putchar
```C
#define  putchar(c)  putc( (c), stdout )
```

- fscanf
```C
int fscanf (FILE* fp, char* format, ...);
```

- fprintf
```C
int fprintf (FILE* fp, char* format, ...);
```

- fclose
```C
int fclose (FILE* fp)
```