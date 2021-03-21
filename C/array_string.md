# Array-String

- strlen()
```C
int strlen (char s[])
{
	int i;

	i = 0;
	while ( s[i] != '\0' )
		++i;
	return i;
}
```

- memset()
```C
void* memset(char s[], char c, int n);
```
> place character c into first n characters of s, return s.