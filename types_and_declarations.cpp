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
  std::cout << "\nsize of int " << sizeof(int);
  std::cout << "\nsize of wchar_t " << sizeof(wchar_t);

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
char str[6] = "fooba";
ptrdiff_t strdiff = &str[5] - &str[0];

// https://en.wikipedia.org/wiki/Data_structure_alignment
/* Data structure alignment is the way data is arranged and accessed in computer memory.
 * It consists of two separate but related issues: data alignment and data structure padding.
 * When a modern computer reads from or writes to a memory address,
 * it will do this in word sized chunks (e.g. 4 byte chunks on a 32-bit system) or larger.
 * Data alignment means putting the data at a memory address equal to some
 * multiple of the word size, which increases the system's performance due to the way the
 * CPU handles memory. To align the data, it may be necessary to insert some meaningless
 * bytes between the end of the last data structure and the start of the next,
 * which is data structure padding. */
auto c  = alignof('c');
auto ai = alignof(1);
auto ad = alignof(2.0);
int a[20];
auto aa = alignof(a); // Alignment of an int

/* The reserved keywords in C++
 * alignas: Align one type as another for faster access
 * bitand: Alternative to &
 * char: Built-in type
 * constexpr: A compile-time constant
 * do: Looping structure
 * extern: Inform the compiler the symbol is defined externally.
 * if
 * new: Allocate memory on the free store.
 * or: Alternative to ||
 * reinterpret_cast: Take a sequence of bytes and re-interpret them
    as another type. Identical to *static_cast<T*>(static_cast<void*>(&x))
 * static_assert: Perform a compile-time assertion.
 * thread_local: Something thread-local is brought into existence during
    thread creation and disposed of when the thread stops 
    // http://stackoverflow.com/questions/11983875/what-does-the-thread-local-mean-in-c11
 * typename: A component of template declarations.
 * volatile: The memory referenced by this variable can be modified by
    an external process.
 * alignof: Alignment of a type.
 * bitor: Equivalent to |
 * char16_t: Built-in type
 * const_cast: Turn a non-const type into a const type, declaring immutability
 * double: Built-in type
 * false
 * inline: Unrolls calls to this function in the underlying assembly.
     Should only be used for very small functions.
 * noexcept: The noexcept operator performs a compile-time check
    that returns true if an expression is declared to not throw any exceptions.
 * or_eq: alternative to |=
 * return
 * static_cast: Conversion using implicit and user-defined methods.
   // http://en.cppreference.com/w/cpp/language/static_cast
 * throw: Throw an exception to be caught by catch.
 * union: Construct a union type
 * wchar_t: Built in type
 * and: Alternative to &&
 * bool
 * char32_t
 * continue: Continue a loop.
 * dynamic_cast: Safely converts pointers and references to classes up,
    down, and sideways along the inheritance hierarchy.
    // http://en.cppreference.com/w/cpp/language/dynamic_cast
 * float
 * int
 * not: Alternative to !
 * private: Class ownership marker
 * short
 * struct
 * true
 * unsigned: Type modifier
 * while: Looping
 * and_eq: Alternative to &=
 * break: Step out of a loop or switch
 * class: Declare a class
 * decltype: The declaration type of an expression. Useful for
    templating.
 * else
 * for
 * long
 * not_eq: Equivalent to !=
 * protected: Class ownership market (only referencable by objects
    of same class or subclass).
 * signed: Type modifier
 * switch: Multiple if statement
 * try: Begin a block that may throw an exception
 * using: Use a namespace or declare a namespace alias.   
 * xor: Alternative to ^
 * asm: Inline assembly code
 * case: Component of switch statement
 * compl: Alternative to ~
 * default: Default code path for switch statement
 * enum: Enumerated type
 * friend: Operator that belongs to a class
 * mutable: applies to non-static class members of non-reference
    non-const type and specifies that the member does not affect the externally visible state of the class
    // http://en.cppreference.com/w/cpp/language/cv
 * nullptr: The best way to mark null pointers (no object).
 * public: Class ownership world-visible marker.
 * sizeof: Built-in size extraction operator (use size_t to hold result).
 * template: Templating.
 * typedef: Alias one type as another name.
 * virtual: May be implemented by a subclass. (If = 0, pure virtual and must be)
 * xor_eq: ^= 
 * auto: Type inference keyword
 * catch: Catch an exception in a try block
 * const: Many uses, but often to do with scope immutability assumptions
 * delete: delete memory on the free store allocated by new 
 * explicit: Never perform implicit type coercion on a function argument.
 * goto: Go to a labeled statement.
 * namespace: Declare a namespace.
 * operator: Define or overload an operator.
 * register: Refer to a specific register in the hardware.
 * static: Within functions, modifiable across multiple calls and retains state.
     For class methods, not part of objects but of class.
 * this: Reference pointer to current object in a class method.
 * typeid: Used where the dynamic type of a polymorphic object must be known and for static type identification.
     // http://en.cppreference.com/w/cpp/language/typeid
 * void: The empty type, only usable as pointer or function return type.
*/

wchar_t* recast(int &an_int, bool reinterpret = false) {
  int* ptrint = &an_int;
  if (reinterpret) {
    return reinterpret_cast<wchar_t*>(ptrint);
  } else {
    return static_cast<wchar_t*>(static_cast<void*>(ptrint));
  }
}

int main(int argc, char **argv) {
  bool aboolean { true };
  // page[size + size] = 7; // Undefined!
  digits();
  limits();
  std::cout << "\nPtr diff: " << static_cast<size_t>(strdiff) << '\n';
  
  static_assert(sizeof(int) == sizeof(wchar_t));
  int secret_message[6] = { (int)'H', (int)'e', (int)'l', (int)'l', (int)'o', 0 };
  // Note the address the pointer is pointing to is 
  // &(*secret_message), whereas the address of the pointer is &secret_message.
  std::cout << "\nSecret message address: " << &(*secret_message);
  wchar_t* str = recast(secret_message[0]);
  std::cout << "\nStr address: " << &(*str) << '\n';
  // Both of these will print "Hello"
  std::wcout << str << '\n'; 
  std::wcout << recast(secret_message[0], true) << '\n';
  return 0;
}

