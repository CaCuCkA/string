#! /bin/bash

RED="\033[31m"
NORMAL="\033[0m"

# Variables
library_dir=library
lib_dir=lib
examples_dir=examples
example_bin_dir=bin/bash
example_obj_dir=examples/obj
dynamic_bin_dir=$lib_dir/bash/dynamic/bin
dynamic_obj_dir=$lib_dir/bash/dynamic/bin
static_obj_dir=$lib_dir/bash/static/obj
static_bin_dir=$lib_dir/bash/static/bin
dependencies=(src/mystring.cpp include/mystring.h)
# Compiler
cxx=g++
cxx_flags=-O3

# Flags
Help() {
  echo "Usage: compile.sh [options]"
  echo "Options:"
  echo "  -h, --help"
  echo "  -cr, --compile-run: Compile and run the example"
  echo "  -c, --compile: Compile only"
  echo "  -r, --run: Run only"
  echo "  --clean: Clean compiled files and build directory"
  echo "  --build_type=Debug/Release: Set build type. Defaults to Debug"
}

DebugMsg() {
  echo "$1"
}

# Compile static and shared libraries
CompileLibraries() {
  mkdir -p $static_bin_dir && mkdir -p $static_obj_dir
  mkdir -p $dynamic_bin_dir && mkdir -p $dynamic_obj_dir

  DebugMsg "Compiling static library..."
  $cxx $cxx_flags -c $library_dir/src/mystring.cpp -o $static_obj_dir/mystring.o
  ar rcs $static_bin_dir/mystring.a $static_obj_dir/mystring.o
  DebugMsg "Compiled successfully. Written to $static_bin_dir/mystring.a"

  DebugMsg "Compiling dynamic library..."
  $cxx $cxx_flags -c $library_dir/src/mystring.cpp -fPIC -o $dynamic_obj_dir/mystring.o
  $cxx $cxx_flags -shared -fPIC -o $dynamic_bin_dir/libmystring.so $dynamic_obj_dir/mystring.o
  DebugMsg "Compiled successfully. Written to $dynamic_bin_dir/libmystring.so"
}

# Compile the example
CompileExample() {
  DebugMsg "Compiling example..."
  mkdir -p $example_bin_dir && mkdir -p $example_obj_dir
  $cxx $cxx_flags -c $examples_dir/example.cpp -o $example_obj_dir/example.o -I$library_dir

  DebugMsg "Linking example with static library..."
  $cxx $cxx_flags -fPIC $example_obj_dir/example.o $static_bin_dir/mystring.a -o $example_bin_dir/static_example
  DebugMsg "Successfully linked with static library. Written to $example_bin_dir/static_example"

  DebugMsg "Linking example with dynamic library..."
  $cxx $cxx_flags -fPIC $example_obj_dir/example.o $dynamic_bin_dir/libmystring.so -o $example_bin_dir/dynamic_example
  DebugMsg "Successfully linked with dynamic library. Written to $example_bin_dir/dynamic_example"
}

# Check state and compile libraries and example if needed
Compile() {
  if CheckUpToDate; then
    echo -e "${RED}Libraries are up to date. Nothing to compile${NORMAL}"
    echo "Do you want to clean-compile? (y/n)"
    read -r answer
    if [ "$answer" == "n" ]; then
      exit 0
    fi

    if Clean; then
      CompileLibraries
      CompileExample
    else
      exit 0
    fi
  else
    CompileLibraries
    CompileExample
  fi
}

# Check if libraries are up to date
CheckUpToDate() {
  if ! CheckCompiled; then
    return 1
  fi

  for file in "${dependencies[@]}"; do
    if [ $library_dir/"$file" -nt $dynamic_bin_dir/libmystring.so ]; then
      return 1
    elif [ $library_dir/"$file" -nt $static_bin_dir/mystring.a ]; then
      return 1
    else
      return 0
    fi
  done
}

# Check if libraries and example are compiled
CheckCompiled() {
  if [[ -f $example_bin_dir/static_example && -f $static_bin_dir/mystring.a ]]; then
    return 0
  elif [[ -f $example_bin_dir/dynamic_example && -f $dynamic_bin_dir/libmystring.so ]]; then
    return 0
  else
    return 1
  fi
}

# Run the example
Run() {
  if CheckCompiled; then
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
      echo "Linux detected. Setting LD_LIBRARY_PATH..."
      echo ""
      echo "With which type of library you want compile your example? (s/d)"
      read -r answer
      if [ "$answer" == "s" ] || [ "$answer" == "S" ]; then
        LIBRARY_PATH="$static_bin_dir" $example_bin_dir/static_example
      elif [ "$answer" == "d" ] || [ "$answer" == "D" ]; then
        LD_LIBRARY_PATH="$dynamic_bin_dir" $example_bin_dir/dynamic_example
      else
        echo -e "${RED}Error: You input incorrect data. Restart..."
        Run
      fi
    elif [[ "$OSTYPE" == "darwin"* ]]; then
      echo "MacOS detected. Setting DYLD_LIBRARY_PATH..."
      echo ""
      echo "With which type of library you want compile your example? (s/d)"
      read -r answer
      if [ "$answer" == "s" ] || [ "$answer" == "S" ]; then
        LIBRARY_PATH="$static_bin_dir" $example_bin_dir/static_example
      elif [ "$answer" == "d" ] || [ "$answer" == "D" ]; then
        DYLD_LIBRARY_PATH="$dynamic_bin_dir" $example_bin_dir/dynamic_example
      else
        echo -e "${RED}Error: You input incorrect data. Restart..."
        Run
      fi
    fi
  else
    echo -e "${RED}Error: nothing to run. Necessary files are not compiled. Run with -c or --compile option to compile.${NORMAL}
            Do you want to automatically compile libraries and run the example? (y/n)"
    read -r answer
    if [[ "$answer" == "y" ]]; then
      Compile
      Run
    else
      echo "Exiting..."
      exit 1
    fi
  fi
}

# Clean compiled files
Clean() {
  echo "This will remove all compiled files along with the library. Are you sure? (y/n)"
  read -r answer
  if [[ "$answer" == "y" ]]; then
    rm -rf $lib_dir/bash
    rm -rf $example_bin_dir
    echo "Cleaned successfully."
    return 0
  else
    echo -e "${RED}Aborted${NORMAL}"
    return 1
  fi
}

# Check if there is no argument
if [ $# -eq 0 ]; then
  Help
  exit 1
fi

# Check if there is more than one argument
if [ $# -gt 1 ]; then
  echo -e "${RED}Error: Too many arguments${NORMAL}"
  Help
  exit 1
fi

# Check if the argument is -h or --help
if [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
  Help
  exit 0
fi

# Check if the argument is -r or --run
if [ "$1" = "-r" ] || [ "$1" = "--run" ]; then
  Run
  exit 0
fi

# Check if the argument is -c or --compile
if [ "$1" = "-c" ] || [ "$1" = "--compile" ]; then
  Compile
  exit 0
fi

# Check if the argument is -cr or --compile-run
if [ "$1" = "-cr" ] || [ "$1" = "--compile-run" ]; then
  Compile
  Run
  exit 0
fi

# Check if the argument is clean
if [ "$1" = "--clean" ]; then
  Clean
  exit 0
fi

# Check if the argument is not valid
if [[ ! " ${valid_args[*]} " == *" $1 "* ]]; then
  echo -e "${RED}Error: Invalid argument${NORMAL}"
  Help
  exit 1
fi
