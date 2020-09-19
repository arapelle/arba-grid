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

## Example - Print a grid

```c++
#include <grid/grid.hpp>
#include <string>
#include <iostream>

int main()
{
    grid::grid<std::string> gr(3,2, "----");
    gr.get(1,1) = "Cool";

    for (uint16_t j = 0; j < gr.height(); ++j)
    {
        for (uint16_t i = 0; i < gr.width(); ++i)
            std::cout << gr.get(i,j) << "  ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (grid::grid_position pos; pos.y() < gr.height(); gr.advance(pos))
        std::cout << "[" << pos << "]: " << gr.get(pos) << std::endl;
    std::cout << std::endl;

    for (const std::string& str : gr)
        std::cout << "[" << gr.value_position(str) << "]: " << str << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
```

## Example - Using *grid* in a CMake project

See the [basic cmake project](https://github.com/arapelle/grid/tree/master/example/basic_cmake_project) example, and more specifically the [CMakeLists.txt](https://github.com/arapelle/grid/tree/master/example/basic_cmake_project/CMakeLists.txt) to see how to use *grid* in your CMake projects.

# License

[MIT License](https://github.com/arapelle/grid/blob/master/LICENSE.md) © grid