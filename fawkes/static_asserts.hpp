#pragma once

#include <cstddef>

namespace fawkes {
    namespace static_asserts {
        template<std::size_t bit_width>
        void byte_aligned() {
            static_assert(bit_width % 8U == 0U, "unaligned bit width");
        }

        template<typename T, std::size_t max_bit_width>
        static void bit_width_at_most() {
            byte_aligned<max_bit_width>(); // no way to get unaligned bit width
            static_assert(sizeof(T) * 8 <= max_bit_width, "bit width too high");
        }
    }
}
