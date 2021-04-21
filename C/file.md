# File

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