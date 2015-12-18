#include <iostream>
using namespace std;

const int x = 10;
constexpr int y = 2 * x;
const int z = 2 * x;

class Vector {
private:
  double *elem;
  int sz;

public:

  Vector(int s) : elem { new double[s] }, sz { s } { }
  int size() { return sz; };
  double &operator[](int i) { 
    if (i < 0 || size() <= i) {
      throw out_of_range("Out of range on Vector::operation[]");
    }
    return elem[i];
  }
};

int main(int argc, char **argv) {

  Vector *v = new Vector(5);
  try {
    std::cout << "Sixth: " << (*v)[6];
  } catch (out_of_range) {
    std::cout << "Vector is out of range";
  }

  for (auto i = 0; i < 10; i++) {
    std::cout << "hi " << i << " " << y << " " << z << std::endl;
  }
  return 0;
}

