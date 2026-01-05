#include <iostream>
#include <vector>

#include "vector/vector.hpp"

int main() {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<std::string> v2{"a", "b", "c"};
  v1.PrintInfoVector();
  v2.PrintInfoVector();
  std::vector<int> v3;
}
