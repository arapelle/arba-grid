#pragma once

#include <concepts>
#include <cstdint>
#include <type_traits>

inline namespace arba
{
namespace grid
{
inline namespace concepts
{

template <typename PositionType>
concept GridPosition = requires(const PositionType& cpos) {
    { cpos.x() } -> std::convertible_to<int32_t>;
    { cpos.y() } -> std::convertible_to<int32_t>;
};

} // namespace concepts
} // namespace grid
} // namespace arba
