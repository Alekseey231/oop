#include "edge.h"


Edge::Edge(const std::size_t start, const std::size_t end) noexcept : start_index(start), end_index(end)
{}

std::size_t Edge::start() const noexcept
{
    return this->start_index;
}

std::size_t Edge::end() const noexcept
{
    return this->end_index;
}

void Edge::set_start(std::size_t const start) noexcept
{
    this->start_index = start;
}
void Edge::set_end(std::size_t const end) noexcept
{
    this->end_index = end;
}