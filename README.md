Adapted from this blog: https://codeforces.com/blog/entry/68809

# How to use debug.h
Place the file in /usr/local/include for Mac
For Windows or Linux, put it wherever you have bits/stdc++.h located

Put `#include<debug.h>` at the top of your cpp file

Usage:

```
vector<int> a = {1, 3, 5};
debug(a)

// prints a = {1, 3, 5} to cerr
```
For online judges, you can use:
```
#ifndef ONLINE_JUDGE
#include<debug.h>
#else
#define debug(...)
#endif
```
Otherwise, replace the first line with `#ifdef VAR` where you define VAR with -D VAR


