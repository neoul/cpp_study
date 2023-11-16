
#include <stdio.h>

// First step: Macro for indirect expansion
#define CONCAT_INTERNAL(a, b) a##b

// Second step: Macro that expands its arguments before concatenating them
#define CONCAT(a, b) CONCAT_INTERNAL(a, b)

// Macro to create a unique variable name with a base name
#define UNIQUE_VAR(base) CONCAT(base, __COUNTER__)

int main()
{
     int UNIQUE_VAR(myVar) = 10; // myVar0
     int UNIQUE_VAR(myVar) = 20; // myVar1

     printf("%d\n", myVar0);
     printf("%d\n", myVar1);

     return 0;
}
