#include <cstdint>
#include <cstdlib>
#include <iostream>

namespace fawkes {
    namespace rust {
        extern "C" std::uint32_t add(std::uint32_t lhs, std::uint32_t rhs);
        extern "C" std::uint32_t fib(std::uint32_t n);
    }

    namespace static_asserts {
        template<std::size_t BitWidth>
        void byte_aligned() {
            static_assert(BitWidth % 8U == 0U, "unaligned bit width");
        }

        template<typename T, std::size_t MaximumBitWidth>
        static void bit_width_at_most() {
            byte_aligned<MaximumBitWidth>(); // no way to get unaligned bit width
            static_assert(sizeof(T) * 8 <= MaximumBitWidth, "bit width too high");
        }
    }

    unsigned int add(unsigned int lhs, unsigned int rhs) {
        static_asserts::bit_width_at_most<unsigned int, 32>();
        return rust::add(lhs, rhs);
    }

    unsigned int fib(unsigned int n) {
        static_asserts::bit_width_at_most<unsigned int, 32>();
        return rust::fib(n);
    }
}

int main() {
    const unsigned int count(20);
    for (unsigned int i(0); i < count; ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << fawkes::fib(i);
    }
    std::cout << ", ...";

    return EXIT_SUCCESS;
}
