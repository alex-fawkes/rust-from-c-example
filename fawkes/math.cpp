#include "math.hpp"

#include "rust.hpp"
#include "static_asserts.hpp"

#include <sstream>

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

        std::string fib_string(unsigned int n) {
            std::stringstream stream;
            for (unsigned int i(0); i < n; ++i) {
                if (i != 0) stream << ", ";
                stream << fawkes::math::fib(i);
            }
            stream << ", ...";
            return stream.str();
        }
    }
}
