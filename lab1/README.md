## UID: 806281561

## Pipe Up

A simulation of the Unix pipe "|"  written in C.

## Building

Enter make into the terminal and it will build the program with both the pipe executable and pipe.o output file.

if not gcc -o pipe.c pipe will also do the same thing 

## Running

```bash
./pipe ls cat wc 
//will return:
    6   6   51

./pipe ls sort uniq 
will return:
cs111@cs111 CS111/lab1 (main %) » ./pipe ls sort uniq 
Makefile
pipe
pipe.c
pipe.o
README.md
test_lab1.py
```
## Cleaning up

make clean will remove all binary files such as the pipe executable, pipe.o, and the __pycache__ directory