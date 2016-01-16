#include <iostream>
#include <string>

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

void numeric_literals() {
  int x = 1;
  long y = 1000000000L;
  long long z = 100000000000000LL;
  unsigned long long w = 1000000000000000ULL;
  double d = 0.539e-10f;
  long double d2 = 0.0539e-15L;
  double d3 = 0776; // octal
  double d4 = 0xf00; // hex
}

void char_literals() {
  char     c1 =  'f';
  char16_t c2 = u'u';
  char32_t c3 = U'l';
  wchar_t  c4 = L'L';
}

void string_literals() {
  const char* s1 = "mess";
  const char* s2 = R"(what a "mess"!)";
  const char* s3 = u8"UTF-8 mess";
  const char16_t* s4 = u"UTF-16 mess";
  const char32_t* s5 = U"UTF-32 mess";
  const wchar_t* s6  = L"UTF-32 wide mess";
  const wchar_t* s6r = LR"(A raw "UTF-32" mess)";
  const wchar_t* s7  = LR"*^^*(A raw ("UTF-32") mess)*^^*";

  // Couldn't get this to work...
  // using namespace std::string_literals;
  // auto x { "string"s };
}

/* Guarantees on type size inequalities:
 * 1 = sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
 * 1 <= sizeof(bool) <= sizeof(long)
 * sizeof(char) <= sizeof(wchar_t) <= sizeof(long)
 * sizeof(float) <= sizeof(double) <= sizeof(long double)
 * sizeof(N) == sizeof(signed N) == sizeof(unsigned N) // N in char, short, int, long, long long
 * char at least 8 bits, short at least 16 bits, long at least 32 bits
*/ 

#include <limits>

void limits() {
  std::cout << "\nsize of long " << sizeof(1L);
  std::cout << "\nsize of long long " << sizeof(1LL);

  std::cout << "\nsize of largest float " << std::numeric_limits<float>::max();
  std::cout << "\nsize of largest double " << std::numeric_limits<double>::max();
}

#include <cstdint>

void int_sizes() {
  int16_t x { 0x0abb}; // 2 bytes
  int64_t y { 0x00aabbbbccccdddd}; // 8 bytes
  int_least16_t z; // At least 2 bytes
  int_least32_t w; // At least 4 bytes
  int_fast32_t u; // Fastest int type with at least 4 bytes
}

#include <cstddef>

// The above header defines size_t: A type big enough to
// hold the size of every object.
size_t x = sizeof(long long);

int main(int argc, char **argv) {
  bool aboolean { true };
  // page[size + size] = 7; // Undefined!
  digits();
  limits();
  return 0;
}

