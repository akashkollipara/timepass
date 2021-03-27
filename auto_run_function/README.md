Auto Run Function
===
This is a program intended to demonstrate a function need not be
called with its name to run it.

A major use case of this method is when you have unknown
number of function, it becomes difficult to add all the
function to main. This program demonstrates a function can
be added to a memory section during compilation with a
data structure and the data structure can be used to run
the function.

---
Dependencies:
* linux machine
* make utility
* gcc

---
make Usage:
```
make <target> <FLAGS>
```
| target  | Description        |
|---------|--------------------|
| default |Builds binary       |
|  clean  |Removes build output|
|   run   |Runs built binary   |

| FLAGS         | Decsription         |
|---------------|---------------------|
| OUT=<path>    |Specify out directory|
| VERBOSE=<0/1> |Output build logs    |
