#include <iostream>

/* Other headers
#include <cstddef>  // types
#include <cfloat>
#include <limits>  
#include <climits>  // Implementation properties
#include <cstdint>  // Integer types
#include <cstdlib>  // Start and termination
#include <new>      // Dynamic memory management
#include <typeinfo> // Type identification
#include <exception> // Exception handling
#include <initializer_list> // Initializer lists
#include <cstdalign>
#include <cstdarg>
#include <cstdbool> // Other run-time support
#include <type_traits> // Type traits
#include <atomic>   // Atomics
*/

/* C++'s fundamental types:
 * boolean (bool)
 * character (char, signed char, unsigned char, wchar_t, char16_t, char32_t)
 * integer (int and long long)
 * floating point (double and long double)
 * void 
 * pointer types (int*)
 * array types (char[])
 * reference types (double& and vector<int>&&)
 * data structures and classes
 * enumeration (enum and enum class)
 */

using namespace std;

const int size = 4 * 1024;
char page[size];

void digits() {
  for (auto x : {0, 1, 2, 3, 4}) {
    // Can use static_cast for simple type conversion on the byte level.
    std::cout << static_cast<char>(65 + x); // ABCDE
  }
}

// char, unsigned char, and signed char are all distinct!
void f(char c, signed char sc, unsigned char uc) {
  //char *pc = &uc;  //error: cannot initialize a variable of type 'char *' with an rvalue of type 'unsigned char *'
  //signed char *psc = pc; // error
  //unsigned char *puc = pc; // error
  //psc = puc; // error: assigning to 'signed char *' from incompatible type 'unsigned char *'
}

void int_literals() {
  int x = 1;
  long y = 1000000000L;
  long long z = 100000000000000LL;
  unsigned long long w = 1000000000000000ULL;
}


int main(int argc, char **argv) {
  bool aboolean { true };
  // page[size + size] = 7; // Undefined!
  digits();
  return 0;
}

