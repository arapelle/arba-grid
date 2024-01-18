#pragma once

#include <arba/math/vec2.hpp>

inline namespace arba
{
namespace grid
{

using grid_position8 = math::vec2i8;
using grid_position16 = math::vec2i16;
using grid_position32 = math::vec2i32;
using grid_position64 = math::vec2i64;

using grid_position = grid_position32;

using grid_offset = math::vec2i32;
using grid_dimension = math::vec2u32;

}
}
