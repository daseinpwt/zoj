# daseinpwt's solutions for ZOJ
## Using own header files
Sometime we might want to have some utility functions in separate header files, to keep the code well organised and easy to maintain. However, ZOJ (actually, almost all the OJs) only supports single C/C++ source file. That means you can not use own header files and you need to copy-paste all the utility functions every time you code for a new problem.

What would be really convenient is:
1. We can write our own utility functions in separate header files and use `#include` to compile, run and test the code locally.
2. When we want to submit the code, the included header files will be automatically inline-replaced.

Inspired by [Using a C preprocessor as an HTML authoring tool](http://jkorpela.fi/html/cpre.html), this idea is implemented by taking advantage of the gcc preprocessor.

To see the detail of the trick, check `cpp.tpl` and the `dist` target in `Makefile.tpl` (The tool `awk` is used in Makefile instead of `sed` because MacOS and Linux use different versions of `sed`).

## Create the folder for a new problem
1. In root, `. create {Problem Number}` (you will enter the created folder automatically)
2. In the created folder, add your own header files (if any) and solution code to `{Problem Number}.cpp`
3. `make run`. The code (`{Problem Number}.cpp`) will be compiled and executed
4. `make dist`. A file `{Problem Number}_dist.cpp` will be generated. You can use that file for submission