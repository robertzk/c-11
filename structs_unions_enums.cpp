#include <iostream>

struct Readout {
  int value;
  char hour;
  char seq;
};

struct Readout2 {
  char hour;
  int value;
  char seq;
};

int main(int argc, char **argv) {
  std::cout << "Size of Readout: " << sizeof(Readout) << '\n';   // 8
  std::cout << "Size of Readout2: " << sizeof(Readout2) << '\n'; // 12
}

