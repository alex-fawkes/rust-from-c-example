#include <cstdlib>
#include <iostream>

extern "C" unsigned int add(unsigned int lhs, unsigned int rhs);

int main() {
  std::cout << "add(40,2) = " << add(40,2) << std::endl;

  return EXIT_SUCCESS;
}
