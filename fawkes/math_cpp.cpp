#include "math.hpp"

#include <sstream>

namespace fawkes {
    namespace math {
        unsigned int add(unsigned int left, unsigned int right) {
            return left + right;
        }

        unsigned int fib(unsigned int n) {
            if (n == 0) return 0;
            if (n == 1) return 1;
            return fib(n - 1) + fib(n - 2);
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
