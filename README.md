# Dasein's solutions for ZOJ
## About ZOJ
ZOJ is an online judge system maintained by Zhejiang University ACM/ICPC Team. It allows people to solve algorithm problems online.

## Dasein's solutions and the solution framework
This repo contains the solutions for ZOJ problems written by daseinpwt. The solutions include the C++ source codes and the problem analyses in pdf format.

A solution framework is developed to accelerate coding and documenting.

### Using own header files
Sometime we might want to have some utility data structures and functions in separate header files, to keep the code well organised and easy to maintain. However, ZOJ (actually, almost all the OJs) only supports single C/C++ source file. That means you can not use own header files and you need to copy-paste all the utility functions every time you code for a new problem.

What would be really convenient is:
1. We can write our own utility functions in separate header files and use `#include` to compile, run and test the code locally.
2. When we want to submit the code, the included header files will be automatically inline-replaced.

Inspired by [Using a C preprocessor as an HTML authoring tool](http://jkorpela.fi/html/cpre.html), this idea is implemented by taking advantage of the gcc preprocessor.

To see the detail of the trick, check `cpp.tpl` and the `dist` target in `Makefile.tpl` (The tool `awk` is used in Makefile instead of `sed` because MacOS and Linux use different versions of `sed`).

### Writing solutions in markdown and latex
By using `pandoc`, we can write text in markdown and latex. You can check [Easy LaTeX with Markdown and Pandoc](http://tech.lauritz.me/easy-latex-with-markdown-pandoc/) for a quick look.

When we run `create`, a file `solution.md` is automatically generated in the problem folder and you can use `make solution` to generate a corresponding pdf file.

### Creating the workspace for a new problem
1. In root directory, `./create {Problem Number}`
2. In the created folder, add your own header files (if any) and solution code to `{Problem Number}.cpp`
3. `make run`. The code (`{Problem Number}.cpp`) will be compiled and executed
4. If you want to compare the program with some standard solution (the AC code), you need to copy-paste the standard solution into `std.cpp` and write code for generating test data in `make_data.py`. After that, you can run `make check` to start the automated checking. When a input which yields different outputs is found, the checking will be terminated and you can find the corresponding input and outputs in the folder `check`
5. `make dist`. A file `{Problem Number}_dist.cpp` will be generated under the folder `build`. You can use that file for submission
6. After AC, you might want to write down your solution. You can do it in `solution.md` and use both markdown and latex grammars. Run `make solution` to generate a corresponding pdf file

### C++11
C++11 features are used in some places. It is always safe to compile the programs with '-std=c++11' flag.