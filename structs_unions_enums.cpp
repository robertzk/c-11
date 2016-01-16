#include <iostream>
#include <sstream>
#include <string>
#include <boost/format.hpp>
using namespace std;

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

struct Address {
  string name;
  int    number;
  string street;
  string town;
  char state[2];
  char zip[5];

  Address(const string &n, int nu, const string &s, const string &t,
          const string &st, int z);

  // Not sure why returning by reference here causes a segfault.
  const std::string to_s() const {
    return (boost::format("%s lives at %d %s, %s %s %s") %
      name % number % street % town % state % zip).str();
  }
  
  friend ostream& operator<<(ostream &, Address);
};

ostream& operator<<(ostream &os, Address a) {
  return os << a.to_s();
}

Address::Address(const string &n, int nu, const string &s, const string &t,
                 const string &st, int z) : name(n), number(nu), street(s), town(t) {
  if (st.size() != 2) {
    throw("State must be of length 2.");
  }

  state[0] = st[0]; state[1] = st[1];
  ostringstream ss;
  ss << z;
  string zi = string { ss.str() };

  switch(zi.length()) {
    case 5:
      for (unsigned int i = 0; i < 5; i++) zip[i] = zi[i];
      break;
    case 4:
      zip[0] = 0;
      for (unsigned int i = 0; i < 4; i++) zip[i + 1] = zi[i];
      break;
    default:
      throw("Invalid ZIP length.");
  }
}

// Some fun with reinterpret cast on structs
struct S1 { int a; };
struct S2 { int a; };

S2 tos2(S1 &a) {
  return *reinterpret_cast<S2*>(&a);
}

S2 tos2(S1 &&a) {
  return *reinterpret_cast<S2*>(&a);
}

int main(int argc, char **argv) {
  std::cout << "Size of Readout: " << sizeof(Readout) << '\n';   // 8
  std::cout << "Size of Readout2: " << sizeof(Readout2) << '\n'; // 12

  Address a { "John Doe", 10, "New Lane", "Cityville", "AL", 6065 };
  std::cout << a << '\n';
  S1 s1 = S1 { 1 };
  std::cout << tos2(s1).a << '\n';
  std::cout << tos2(S1 { 2 }).a << '\n'; // Using rvalue ref
}

