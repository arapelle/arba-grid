#pragma once

#include <type_traits>

#include "grid_position.hpp"
#include "../grid_types.hpp"

inline namespace arba
{
namespace grid
{
inline namespace concepts
{

template <typename GridType>
concept Grid = requires(const GridType& cgr)
{
    typename GridType::value_type;
    { cgr.width() } -> std::convertible_to<unsigned>;
    { cgr.height() } -> std::convertible_to<unsigned>;
}
&& requires(const GridType& cgr, GridType& gr, int32_t x, int32_t y)
{
    { cgr.get(x, y) } -> std::same_as<const typename GridType::value_type&>;
    { gr.get(x, y) } -> std::same_as<typename GridType::value_type&>;
}
&&
((requires(const GridType& cgr, GridType& gr, grid_position gp)
{
   { cgr.get(gp) } -> std::same_as<const typename GridType::value_type&>;
   { gr.get(gp) } -> std::same_as<typename GridType::value_type&>;
}
&& requires(const GridType& cgr, GridType& gr, grid_position8 gp)
{
   { cgr.get(gp) } -> std::same_as<const typename GridType::value_type&>;
   { gr.get(gp) } -> std::same_as<typename GridType::value_type&>;
}
&& requires(const GridType& cgr, GridType& gr, grid_position16 gp)
{
   { cgr.get(gp) } -> std::same_as<const typename GridType::value_type&>;
   { gr.get(gp) } -> std::same_as<typename GridType::value_type&>;
}
&& requires(const GridType& cgr, GridType& gr, grid_position64 gp)
{
   { cgr.get(gp) } -> std::same_as<const typename GridType::value_type&>;
   { gr.get(gp) } -> std::same_as<typename GridType::value_type&>;
})
||
(requires(const GridType& cgr, GridType& gr, grid_position gp)
{
   { cgr[gp] } -> std::same_as<const typename GridType::value_type&>;
   { gr[gp] } -> std::same_as<typename GridType::value_type&>;
}
&& requires(const GridType& cgr, GridType& gr, grid_position8 gp)
{
   { cgr[gp] } -> std::same_as<const typename GridType::value_type&>;
   { gr[gp] } -> std::same_as<typename GridType::value_type&>;
}
&& requires(const GridType& cgr, GridType& gr, grid_position16 gp)
{
   { cgr[gp] } -> std::same_as<const typename GridType::value_type&>;
   { gr[gp] } -> std::same_as<typename GridType::value_type&>;
}
&& requires(const GridType& cgr, GridType& gr, grid_position64 gp)
{
   { cgr[gp] } -> std::same_as<const typename GridType::value_type&>;
   { gr[gp] } -> std::same_as<typename GridType::value_type&>;
}))
;

}
}
}
