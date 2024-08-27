/* 
    Symbolic representation of address 
    "Call by reference"
    int num = 5 ; // allocating 5 in 0x... address (hexadecimal way)

    Syntax: datatype * var_name

    Symbol table is a data structure created & maintained by the compiler in order to keep track of semantics of variables. It stores information about scope & binding information about * name    * class objects

    Operations of symbol table: allocate, free, lookup, insert, set architecture, get attribute 

    Address operator: &var_name

    int *ptr  ;  // Garbage value 
    int *ptr  = &num ; // Always saves memory   

    // * num and ptr should be of the same type 

    Example
    ______          ______  
    |    |         |      |                    
    | 5  |         |  100 | 
    |____|         |______|
    num             ptr 
    addr = 100

    In ptr 100 address & in 100 address num is there
    ptr is a pointer to int num 

    num++  *ptr or num = 6

    sizeof(ptr) // 8 bytes in every case (int, double, char, etc)

    If we try to access null memory (which is not allocated previously), an error occurs "segment fault"  

    Segment fault occurs like in:   int *p = 0 ; cout << p;

    Two ptrs can have the same address when pointing to the same num also
    int *ptr1  = &num ;
    int *ptr2  = &num ;

    (*ptr)++ increases original num also 
    int num = 5 ; 
    int *ptr1 = &num ;
    int *ptr2 = ptr1 ;

    // Output of *ptr++ and (*ptr)++ will be the same
    
    ptr += n;
    where n is an integer 
    it adds 4*n bits to the final address from the initial address

    Similarly, ptr -= n
    it subtracts 4*n bits from the final address from the initial address

    Also, remember the address is in hexadecimal format 
 */

#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    int *ptr = &num;

    // cout << (*ptr == num) ; // this tells that *ptr and num are equal

    // num++;
    // cout << *ptr << num << endl ; // both become 6

    // int *ptr1 = &num ;
    // int *ptr2 = &num ;
    // cout << (ptr1 == ptr2) << (*ptr1 == *ptr2); // both are true: ptr1 and ptr2 are equal, *ptr1 and *ptr2 are equal

    // cout << "Before " << ptr << endl ; // Before 0x7ffc3c49bbfc
    // cout << "After" << ++ptr << endl ; // After  0x7ffc3c49bc00      
    // // 4 bytes differ from the previous 


    // cout << "Value pointed to by ptr: " << *ptr << endl; //  5 
    // *ptr = 10; // Modify the value pointed to by ptr
    // cout << "Modified value of num: " << num << endl; // 10

    // int *ptr_dynamic = new int; // Allocate memory for an integer
    // cout << "Dynamically allocated value: " << *ptr_dynamic << endl; // 0
    // *ptr_dynamic = 20; // Assign a value to the dynamically allocated memory
    // cout << "Dynamically allocated value: " << *ptr_dynamic << endl; //20
    // delete ptr_dynamic; // Deallocate memory to prevent memory leaks


    // int arr[5] = {1, 2, 3, 4, 5};
    // int *ptr_arr = arr; // Pointer to the first element of the array
    // for (int i = 0; i < 5; ++i) 
    //     cout << "Element " << i << ": " << *(ptr_arr + i) << endl; // Access array elements using pointer arithmetic
    /* Element 0: 1
    Element 1: 2
    Element 2: 3
    Element 3: 4
    Element 4: 5 */


    




    return 0;
}
