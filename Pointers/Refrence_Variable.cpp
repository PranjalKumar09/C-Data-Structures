/*

1. Reference Variables:
   - A reference variable is an alias for an existing variable (same memory, different name).
   - Syntax: 
        data_type &referenceName = existing_variable;
   - Example:
        int i = 5;
        int &j = i;  // j is a reference to i, so i and j both equal 5.
   - Use in pass-by-reference to avoid copying memory.

2. Dynamic Memory Allocation with Pointers:
   - Use the new keyword to allocate memory on the heap.
   - Syntax:
        data_type *pointer_variable = new data_type[size];
   - Example:
        int *arr = new int[5];  // Allocates an array of 5 integers.
        // Remember to free the memory:
        delete[] arr;
   - Note: Do not declare arrays with non-constant sizes like "int arr[n];" if n is not known at compile time.

3. Memory Areas: Stack vs. Heap:
   - Stack Memory:
        * Allocated at compile time for local variables.
        * Example: int arr[5]; (stored on the stack)
        * Automatically released when the variable goes out of scope.
   - Heap Memory:
        * Allocated at runtime using new.
        * Example: int *arr = new int[5];
        * Must be manually released using delete or delete[].

4. Pointer Sizes:
   - 64-bit system: typically 8 bytes.
   - 32-bit system: typically 4 bytes.
   - Example: 
        int *arr = new int[5];
        // Pointer size (dynamicArr) is the size of the pointer, not the array it points to.

5. Type Casting Pointers:
   - You can cast pointers to different types using type casting.
   - Example with an int cast to a char pointer:
        int l = 65;
        char *ch = (char *)&l; // Interprets the address of l as a char pointer.
        // *ch will be 'A', since 65 is the ASCII value for 'A'.

Additional Good Practices:
   - Always free dynamically allocated memory using delete/delete[].
   - Avoid dereferencing NULL or uninitialized pointers (wild pointers).
   - Do not modify string literals via pointers (e.g., char* c = "abcde";).
*/

#include <iostream>
using namespace std;

// Function demonstrating reference variables
void demonstrateReferenceVariable() {
    int i = 5;
    int &j = i;
    cout << "Reference Variable:" << endl;
    cout << "i = " << i << ", j = " << j << endl;
}

// Function demonstrating dynamic memory allocation
void demonstrateDynamicMemoryAllocation() {
    int size = 5;
    int *arr = new int[size]; // Allocates memory for 5 integers on the heap
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }

    cout << "\nDynamic Memory Allocation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Deallocating memory to prevent memory leaks
    delete[] arr;
}

// Function demonstrating static vs. dynamic memory allocation
void demonstrateStaticVsDynamicMemory() {
    int staticArr[5];              // Static allocation (on the stack)
    int *dynamicArr = new int[5];    // Dynamic allocation (on the heap)

    cout << "\nStatic vs. Dynamic Memory:" << endl;
    cout << "Size of staticArr: " << sizeof(staticArr) << " bytes" << endl;
    cout << "Size of dynamicArr (pointer size): " << sizeof(dynamicArr) << " bytes" << endl;

    // Deallocating dynamic memory
    delete[] dynamicArr;
}

// Function demonstrating pointer type casting
void demonstrateTypeCastingPointer() {
    char *ch;
    int l = 65;
    ch = (char *)&l; // Casting the address of l to a char pointer
    cout << "\nPointer Type Casting:" << endl;
    cout << "ch = " << *ch << endl; // Expected output: A (ASCII 65)
}

int main() {
    demonstrateReferenceVariable();
    demonstrateDynamicMemoryAllocation();
    demonstrateStaticVsDynamicMemory();
    demonstrateTypeCastingPointer();
    return 0;
}
