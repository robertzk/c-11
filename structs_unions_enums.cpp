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
  Address() = default;

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
  zi.shrink_to_fit();

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

int toint(S1 &&a) {
  return *reinterpret_cast<int*>(&a);
}

// PODs https://en.wikipedia.org/wiki/Passive_data_structure
#include <type_traits>
template<typename T>
void is_a_pod(const T& object, const char* name) {
  std::cout << name << " is " <<
    (is_pod<T>::value ? "" : "not ") << "a pod.\n";
}

// Bit fields
struct BitFieldCompact {
  bool bit1 : 1;
  bool bit2 : 1;
  bool bit3 : 1;
  bool bit4 : 1;
  bool bit5 : 1;
  bool bit6 : 1;
  bool bit7 : 1;
  bool bit8 : 1;
};

struct BitField {
  bool bit1;
  bool bit2;
  bool bit3;
  bool bit4;
  bool bit5;
  bool bit6;
  bool bit7;
  bool bit8;
};

int main(int argc, char **argv) {
  std::cout << "Size of Readout: " << sizeof(Readout) << '\n';   // 8
  std::cout << "Size of Readout2: " << sizeof(Readout2) << '\n'; // 12

  Address a { "John Doe", 10, "New Lane", "Cityville", "AL", 6065 };
  std::cout << a << '\n';
  S1 s1 = S1 { 1 };
  std::cout << tos2(s1).a << '\n';
  std::cout << tos2(S1 { 2 }).a << '\n'; // Using rvalue ref
  std::cout << toint(S1 { 3 }) << '\n'; 

  // PODs
  is_a_pod(int {}, "int");
  is_a_pod(a, "Address");
  is_a_pod(Readout {}, "Readout");
  is_a_pod(new int, "int*");

  // Bit fields
  BitFieldCompact b1 = { true, false, true, false, true, false, true, true };
  BitField b2 = { true, false, true, false, true, false, true, true };
  std::cout << "BitFieldCompact has size " << sizeof(b1) << '\n';
  std::cout << "BitField has size " << sizeof(b2) << '\n';
}

