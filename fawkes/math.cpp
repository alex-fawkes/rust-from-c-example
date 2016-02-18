#include "math.hpp"

#include "rust.hpp"
#include "static_asserts.hpp"

namespace fawkes {
    namespace math {
        unsigned int add(unsigned int lhs, unsigned int rhs) {
            static_asserts::bit_width_at_most<unsigned int, 32>();
            return rust::add(lhs, rhs);
        }

        unsigned int fib(unsigned int n) {
            static_asserts::bit_width_at_most<unsigned int, 32>();
            return rust::fib(n);
        }
    }
}
