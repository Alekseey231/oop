#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
    public:
        Edge() = default;
        Edge(const std::size_t start, const std::size_t end) noexcept;
        Edge(const Edge &edge) noexcept = default;

        ~Edge() = default;

        std::size_t start() const noexcept;
        std::size_t end() const noexcept;

        void set_start(std::size_t const start) noexcept;
        void set_end(std::size_t const end) noexcept;

    private:
        std::size_t start_index;
        std::size_t end_index;
};

#endif