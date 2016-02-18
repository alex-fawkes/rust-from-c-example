#include <cstdlib>
#include <iostream>

extern "C" unsigned int add(unsigned int lhs, unsigned int rhs);
extern "C" unsigned int fib(unsigned int n);

int main() {
    const unsigned int count(20);
    for (unsigned int i( 0 ); i < count; ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << fib(i);
    }
    std::cout << ", ...";

    return EXIT_SUCCESS;
}
