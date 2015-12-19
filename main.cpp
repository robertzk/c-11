#include <iostream>
using namespace std;

const int x = 10;
constexpr int y = 2 * x;
const int z = 2 * x;

class Vector {
private:
  double *elem;
  size_t sz;

public:

  Vector(unsigned int s) : elem { new double[s] }, sz { s } { }
  Vector(std::initializer_list<double> lst) : elem { new double[lst.size()] }, sz { lst.size() } {
    std::copy(lst.begin(), lst.end(), elem);
  }
  size_t size() { return sz; };
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

  Vector v2 = {1.0, 5.0, 10.0};
  std::cout << "\nv2: " << v2[1] << std::endl;


  for (auto i = 0; i < 10; i++) {
    std::cout << "hi " << i << " " << y << " " << z << std::endl;
  }
  return 0;
}

