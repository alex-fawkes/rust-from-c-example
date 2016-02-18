#pragma once

#include <cstdint>

namespace fawkes {
    namespace rust {
        extern "C" std::uint32_t add(std::uint32_t lhs, std::uint32_t rhs);
        extern "C" std::uint32_t fib(std::uint32_t n);
    }
}
