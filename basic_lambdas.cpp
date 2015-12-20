#include <iostream>
#include <vector>
#include <algorithm>

template<typename C, typename P>
std::vector<typename C::iterator> find_all(C &c, P pred) {
  std::vector<typename C::iterator> res;
  for (auto p = c.begin(); p != c.end(); ++p) {
    if (pred(*p)) {
      res.push_back(p);
    }
  }
  
  return res;
}

/*
// The template above specializes to:
std::vector<std::vector<int>::iterator> find_all(std::vector<int> &c, bool (*pred)(const int)) {
  std::vector<std::vector<int>::iterator> res;
  for (auto p = c.begin(); p != c.end(); ++p) {
    if (pred(*p)) {
      res.push_back(p);
    }
  }

  return res;
}
*/

struct comp {
  bool operator()(const int i) { return i % 2 == 0; }
};

int main(int argc, char** argv) {
  std::vector<int> numbers { -5, 3, 10, 11, 15, 19, 22 };
  std::vector<int> evens;
  copy_if(numbers.begin(), numbers.end(),
    std::back_inserter(evens),
    [](const int x) { return x % 2 == 0; } // or comp()
  );

  // Prints 10 and 22
  std::copy(evens.begin(), evens.end(),
    std::ostream_iterator<int> { std::cout, "\n" });

  // Prints 3, 11, 15, 19
  for (auto &p : find_all(numbers, [](const int x) { return x % 2 == 1; })) {
    std::cout << *p << std::endl;
  }
      
  return 0;
}

