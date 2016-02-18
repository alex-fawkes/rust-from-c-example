#include <cstdlib>
#include <fawkes/math.hpp>
#include <fawkes/rust.hpp>
#include <fawkes/static_asserts.hpp>
#include <iostream>

int main() {
    const unsigned int count(20);
    for (unsigned int i(0); i < count; ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << fawkes::math::fib(i);
    }
    std::cout << ", ...";

    return EXIT_SUCCESS;
}
