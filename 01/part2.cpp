#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int fuel(int mass) {
  return std::floor(mass / 3) - 2;
}

int fuelForModule(int mass) {
  auto total = 0;
  for (;;) {
    mass = fuel(mass);
    if (mass <= 0) {
      break;
    }
    total += mass;
  }
  return total;
}

int main() {
  std::ifstream file{"input1.txt"};
  std::string token;
  std::vector<int> numbers;
  while (file >> token) {
    numbers.push_back(std::atoi(token.c_str()));
  }
  std::transform(numbers.begin(), numbers.end(), numbers.begin(), fuelForModule);
  std::cout << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
}
