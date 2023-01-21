# String library
Authors (team): <a src="https://github.com/CaCuCkA">Mykola Yakovkin</a>
## Prerequisites

- CMake 3.14 or higher. make 3.81 or higher.

- Compiler with C++14 and C11 support. GCC 4.9 or higher, Clang 3.4 or higher, MSVC 16.8 or higher are recommended.

- Git

- Bash

- C++ IDE (optional). CLion is recommended.

### Installation
To install our library you need to:
```asm
$ mkdir ~/workspace
$ cd ~/workspace
$ git clone https://github.com/ucu-cs/lab2_make_cmake-yakovkin_varanytsa
$ cd lab2_make_cmake-yakovkin_varanytsa
```
### Compilation
How to compile <strong>our string library</strong>
### Using `compile.sh`
To compile the library you need to use the following command:
```bash
$ ./compile.sh -cr
```
`--clean` option can be used to clean the build directory.For example, if you want to clean the build directory and compile the libraries, use the following commands:
```bash
$ ./compile.sh --clean
$ ./compile.sh -c
```
### Using `Make`
To compile the library you need to:
```bash
$ make TARGET_NAME=dynamic 
```
OR
```asm
$ make TARGET_NAME=static 
```

### Using `CMake`
Our library also supports CMake.
To build the project, you need to:
```bash
$ cmake -B build
$ cmake --build build
```
To run it, use:
```bash
$ ./bin/tests
```

