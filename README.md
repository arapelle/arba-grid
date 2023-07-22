# Concept

The purpose is to provide simple C++ tools to manipulate 2D grid objects.

# Install

## Requirements

Binaries:

- A C++20 compiler (ex: g++-13)
- CMake 3.26 or later

Libraries:

- [math](https://github.com/arapelle/math) 0.4.0 or later

Testing Libraries (optional):

- [Google Test](https://github.com/google/googletest) 1.13 or later (optional)

## Clone
```
git clone https://github.com/arapelle/arba-grid --recurse-submodules
```

## Quick Install

There is a cmake script at the root of the project which builds the library in *Release* mode and install it (default options are used).

```
cd /path/to/arba-grid
cmake -P cmake/scripts/quick_install.cmake
```

Use the following to quickly install a different mode.

```
cmake -P cmake/scripts/quick_install.cmake -- TESTS BUILD Debug DIR /tmp/local
```

## Uninstall

There is a uninstall cmake script created during installation. You can use it to uninstall properly this library.

```
cd /path/to/installed-arba-grid/
cmake -P uninstall.cmake
```

# How to use

## Example - Print a grid

```c++
#include <arba/grid/grid.hpp>
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

See *basic_cmake_project* example, and more specifically the *CMakeLists.txt* to see how to use *grid* in your CMake projects.

# License

[MIT License](./LICENSE.md) © grid
