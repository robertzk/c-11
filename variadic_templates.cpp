#include <iostream>
using namespace std;

template<typename T>
void newprint(T obj) {
  std::cout << obj << std::endl;
}

template<typename T, typename... R>
void newprint(T obj, R... rest) {
  std::cout << obj << std::endl;
  newprint(rest...);
}

int main(int argc, char** argv) {
  newprint(1, "foo", true);

  return 0;
}

