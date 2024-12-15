---
title: "Array String"
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