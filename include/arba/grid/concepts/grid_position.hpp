#pragma once

#include <concepts>
#include <type_traits>
#include <cstdint>

inline namespace arba
{
namespace grid
{
inline namespace concepts
{

template <typename PositionType>
concept GridPosition = requires(const PositionType& cpos)
{
    { cpos.x() } -> std::convertible_to<int32_t>;
    { cpos.y() } -> std::convertible_to<int32_t>;
};

}
}
}
