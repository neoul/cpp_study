// macro__COUNTER__.cpp
// Demonstration of __COUNTER__, assigns unique identifiers to
// different objects of the same type.
// Compile by using: cl /EHsc /W4 macro__COUNTER__.cpp
#include <stdio.h>

class exampleClass {
    int m_nID;
public:
    // initialize object with a read-only unique ID
    exampleClass(int nID) : m_nID(nID) {}
    int GetID(void) { return m_nID; }
};


// First step: Macro for indirect expansion
#define CONCAT_INTERNAL(a, b) a##b

// Second step: Macro that expands its arguments before concatenating them
#define CONCAT(a, b) CONCAT_INTERNAL(a, b)

// Macro to create a unique variable name with a base name
#define UNIQUE_VAR(base) CONCAT(base, __COUNTER__)

int main()
{
    // __COUNTER__ is initially defined as 0
    exampleClass e1(__COUNTER__);

    // On the second reference, __COUNTER__ is now defined as 1
    exampleClass e2(__COUNTER__);

    // __COUNTER__ is now defined as 2
    exampleClass e3(__COUNTER__);

    printf("e1 ID: %i\n", e1.GetID());
    printf("e2 ID: %i\n", e2.GetID());
    printf("e3 ID: %i\n", e3.GetID());

     int UNIQUE_VAR(myVar) = 10; // myVar0
     int UNIQUE_VAR(myVar) = 20; // myVar1
     printf("%d\n", myVar3);
     printf("%d\n", myVar4);

    return 0;
}