#include <arba/grid/grid.hpp>
#include <arba/grid/version.hpp>
#include <string>
#include <iostream>

int main()
{
    arba::grid::grid<std::string> gr(3,2, "----");
    gr.get(1,1) = "Cool";

    for (uint16_t j = 0; j < gr.height(); ++j)
    {
        for (uint16_t i = 0; i < gr.width(); ++i)
            std::cout << gr.get(grid::grid_position(i,j)) << "  ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
