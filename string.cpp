#include <iostream>
#include <string>
using namespace std;

string compose2(const string &a, const string &b, string sep = ":") {
  return a + sep + b;
}

int main(int argc, char** argv) {
  auto str = compose2("foo", "bar");
  std::cout << compose2("foo", "bar");
}

