# regex-matcher

Simple Regex pattern matcher built during my learning.
This uses recursion to match patterns, it is based on brian kernighan's explanation of 
Rob Pike's simple regex code ([Regular expression matcher](https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html)).

New features/patches/bug fixes will be added when I finish working on them,
currently I am focusing on computer architecture, so it will late.

I added my own impleamentaions of range regex search e.g: [a-f] and,
any_of eg:[aeiou] pattern matching and so on.

# Usage
`./reg [PATTERN] -f filename`    for PATTERN searching on specific file called filename.

(or)

`./reg [PATTERN] -.`    Searches for PATTERN on all files in the directory it was ran.

current it search binary files also, I will fix that later.
# How to build
This is a simple program with simple makefile 
simply clone the repo
`git clone https://github.com/venkatesh-coder/regex-matcher.git`
and just run 
`make` on root folder, 
I will refactor the program structure soon.

## dependencies

C compiler and `make` utility.

