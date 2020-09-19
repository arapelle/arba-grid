# Concept

The purpose is to provide simple C++ tools to manipulate 2D grid objects.

See [task board](https://app.gitkraken.com/glo/board/X2R4tCQxbQAR8JQl) for future updates and features.

# Install

## Requirements

Binaries:

- A C++20 compiler (ex: g++-10)
- CMake 3.16 or later

Libraries:

- [Google Test](https://github.com/google/googletest) 1.10 or later (only for testing)

## Clone

```
git clone https://github.com/arapelle/grid --recurse-submodules
```

## Quick Install

There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).

```
cd /path/to/grid
cmake -P cmake_quick_install.cmake
```

Use the following to quickly install a different mode.

```
cmake -DCMAKE_BUILD_TYPE=Debug -P cmake_quick_install.cmake
```

## Uninstall

There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.

```
cd /path/to/installed-grid/
cmake -P cmake_uninstall.cmake
```

# How to use

## Example - 

```c++
#include <iostream>

int main()
{
    return EXIT_SUCCESS;
}
```

## Example - 

```c++
#include <iostream>

int main()
{
    return EXIT_SUCCESS;
}
```

## Example - Using *grid* in a CMake project

See the [basic cmake project](https://github.com/arapelle/grid/tree/master/example/basic_cmake_project) example, and more specifically the [CMakeLists.txt](https://github.com/arapelle/grid/tree/master/example/basic_cmake_project/CMakeLists.txt) to see how to use *grid* in your CMake projects.

# License

[MIT License](https://github.com/arapelle/grid/blob/master/LICENSE.md) © grid