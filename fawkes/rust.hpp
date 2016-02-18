#pragma once

#include <cstdint>

namespace fawkes {
    namespace rust {
        extern "C" std::uint32_t add(std::uint32_t left, std::uint32_t right);
        extern "C" std::uint32_t fib(std::uint32_t n);
    }
}
