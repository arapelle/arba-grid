#pragma once

#include "grid_types.hpp"

inline namespace arba
{
namespace grid
{

class grid_base
{
protected:
    inline grid_base() : dimension_(0, 0) {}
    inline grid_base(unsigned width, unsigned height) : dimension_(width, height) {}
    inline explicit grid_base(const grid_dimension& dimension) : dimension_(dimension) {}

public:
    inline const grid_dimension& dimension() const { return dimension_; }
    inline grid_dimension::number width() const { return dimension_.x(); }
    inline grid_dimension::number height() const { return dimension_.y(); }
    inline bool empty() const { return dimension_ == grid_dimension(); }

    inline bool contains(grid_position::number i, grid_position::number j) const;
    inline bool contains(const grid_position& pos) const { return contains(pos.x(), pos.y()); }

    inline void advance(grid_position& position) const;
    inline grid_position next(grid_position position) const;

    inline void advance_backward(grid_position& position) const;
    inline grid_position previous(grid_position position) const;

    inline bool operator==(const grid_base& rhs) const = default;

protected:
    inline grid_dimension& mutable_dimension() { return dimension_; }
    inline void swap(grid_base& other) { std::swap(dimension_, other.dimension_); }

private:
    grid_dimension dimension_;
};

// grid_base implementation:

bool grid_base::contains(grid_position::number i, grid_position::number j) const
{
    return i >= 0 && static_cast<grid_dimension::number>(i) < dimension_.x()
            && j >= 0 && static_cast<grid_dimension::number>(j) < dimension_.y();
}

void grid_base::advance(grid_position& position) const
{
    auto div = std::div(++position.x(), width());
    position.x() = div.rem;
    position.y() += div.quot;
}

grid_position grid_base::next(grid_position position) const
{
    advance(position);
    return position;
}

void grid_base::advance_backward(grid_position& position) const
{
    if (position.x() == 0)
    {
        position.x() = width();
        --position.y();
    };
    --position.x();
}

grid_position grid_base::previous(grid_position position) const
{
    advance_backward(position);
    return position;
}

}
}
