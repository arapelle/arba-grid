#pragma once 

#include "grid_base.hpp"
#include <vector>

inline namespace arba
{
namespace grid
{

template <typename valuetype>
class grid : public grid_base
{
    using base = grid_base;

public:
    using value_type = valuetype;
    using value_range = std::vector<value_type>;
    using reference = typename value_range::reference;
    using const_reference = typename value_range::const_reference;
    using pointer = typename value_range::pointer;
    using const_pointer = typename value_range::const_pointer;
    using iterator = typename value_range::iterator;
    using const_iterator = typename value_range::const_iterator;

public:
    inline grid() : base() {}
    inline grid(grid_dimension::number_type width, grid_dimension::number_type height, const value_type& value = value_type());
    inline explicit grid(const grid_dimension& dim, const value_type& value = value_type());

    inline const_reference get(int i, int j) const { return data_[j * this->width() + i]; }
    inline const_reference get(const grid_position& pos) const { return get(pos.x(), pos.y()); }
    inline const_reference operator[](const grid_position& pos) const { return get(pos.x(), pos.y()); }
    inline reference get(int i, int j) { return data_[j * this->width() + i]; }
    inline reference get(const grid_position& pos) { return get(pos.x(), pos.y()); }
    inline reference operator[](const grid_position& pos) { return get(pos.x(), pos.y()); }

    inline const_iterator begin() const { return data_.begin(); }
    inline iterator begin() { return data_.begin(); }
    inline const_iterator cbegin() const { return begin(); }
    inline const_iterator end() const { return data_.end(); }
    inline iterator end() { return data_.end(); }
    inline const_iterator cend() const { return end(); }

    inline grid_position value_position(const value_type& ref) const;
    inline grid_position iterator_position(const_iterator iter) const { return value_position(*iter); }
    inline grid_position iterator_position(iterator iter) { return value_position(*iter); }
    inline const_iterator iterator_at(const grid_position& position) const { return begin() + (position.y() * width() + position.x()); }
    inline iterator iterator_at(const grid_position& position) { return begin() + (position.y() * width() + position.x()); }

    inline const_pointer data() const { return data_.data(); }
    inline pointer data() { return data_.data(); }

    void clear();
    void resize(grid_dimension::number_type width, grid_dimension::number_type height, const value_type& value = value_type());
    void resize(const grid_dimension& dimension, const value_type& value = value_type());

    void swap(grid& other);

    inline bool operator==(const grid& rhs) const = default;
    inline bool operator!=(const grid& rhs) const = default;

private:
    std::vector<value_type> data_;
};

// grid implementation:

template<typename valuetype>
grid<valuetype>::grid(grid_dimension::number_type width, grid_dimension::number_type height, const value_type &value)
    : base(width, height), data_(width * height, value)
{}

template<typename valuetype>
grid<valuetype>::grid(const grid_dimension &dim, const value_type &value)
    : base(dim), data_(dim.x() * dim.y(), value)
{}

template <typename valuetype>
grid_position grid<valuetype>::value_position(const grid::value_type &ref) const
{
    std::lldiv_t div = std::lldiv(&ref - data(), width());
    return grid_position(div.rem, div.quot);
}

template<typename valuetype>
void grid<valuetype>::clear()
{
    this->mutable_dimension() = grid_dimension();
    data_.clear();
}

template <typename valuetype>
void grid<valuetype>::resize(grid_dimension::number_type width, grid_dimension::number_type height, const value_type &value)
{
    if (this->width() == width)
        data_.resize(width * height, value);
    else
    {
        value_range data(width * height, value);
        for (unsigned j = 0, endj = std::min(this->height(), height); j < endj; ++j)
            for (unsigned i = 0, endi = std::min(this->width(), width); i < endi; ++i)
                data[j * width + i] = std::move(get(i,j));
        data_ = std::move(data);
    }
    this->mutable_dimension() = grid_dimension(width, height);
}

template <typename valuetype>
void grid<valuetype>::resize(const grid_dimension &dimension, const value_type &value)
{
    resize(dimension.x(), dimension.y(), value);
}

template <typename valuetype>
void grid<valuetype>::swap(grid &other)
{
    base::swap(other);
    std::swap(data_, other.data_);
}

}
}
