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

using namespace std;

const int size = 4 * 1024;
char page[size];

int main(int argc, char **argv) {
  // page[size + size] = 7; // Undefined!
  return 0;
}

