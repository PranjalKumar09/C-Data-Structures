/* 
Reference Variable => refers to the address of another variable

                     Same memory but different names 

Syntax => Data_type  Variable_name = & exisiting_variable

int i = 5;
int &j = i;
//then i = j = 5

Why?
In pass-by new memeory copy created no updation in orignal value in funciton in refrence by no new memory value in function
 we cant create refrence return as it (refrence) is local valribale  -> No acess     | Error | Bad practice do 

For similar reason we cant return pointer 


        
 data_type *pointer_variable   = new data_type[size] ; 
 * sgin indicates we are creating pointer variable 
 pointer variable points address of a array object , which created using new operation


   
NOT DO LIKE IN FUNCTION 
int arr[n]; //complie time we should know 

it return error because memory allocated & memory required  difference result to program crash.



MUCH BETTER THAN above 
int arr[10000];







Program start 

stack (compilied time ) by int arr[n] //stack memory allocated
stack utilise all no heap utlised


Heap -> acess heap memory by "new" keyword

new char || address return

if sufficent memory available it allocate

char *ch = new char


pointer size 
8 byte  = 64 bit system 
4 byte  = 32 bit system 


(8 byte in stack) (heap 5*4 = 20)
int *arr         =  new int[5]  -> can donr in 1 line






Static vs Dyanmic


Static -> int arr[5]    //20 byte
Dynamic -> int *arr = new int[5]  //8 + 20 byte

Static -> 
while (1)
 int i = 5;
create cleavage of 1 integer only

Dynamic ->
while (1)
 int *p = 5;
Program clash


Static -> Memory automatically relase
Dynamic -> Manually release data by "delete" keyword 
int *arr
delete []arr





Type Casting pointer 
char *ch ;
int l = 65;
p = (char *)& l ; // p = A
 */

#include <iostream>

using namespace std;

void demonstrateReferenceVariable() {
    int i = 5;
    int &j = i;
    cout << "i = " << i << ", j = " << j << endl;
}

void demonstrateDynamicMemoryAllocation() {
    // Dynamic memory allocation
    int size = 5;
    int *arr = new int[size]; // Allocating memory for an array of 5 integers
    for (int i = 0; i < size; ++i) 
        arr[i] = i * 10;
    

    // Accessing the allocated memory
    cout << "Dynamic Memory Allocation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Deallocating memory
    delete[] arr;
}

void demonstrateStaticVsDynamicMemory() {
    // Static memory allocation
    int staticArr[5]; // Allocating an array of 5 integers statically

    // Dynamic memory allocation
    int *dynamicArr = new int[5]; // Allocating an array of 5 integers dynamically

    cout << "Size of staticArr: " << sizeof(staticArr) << " bytes" << endl;
    cout << "Size of dynamicArr: " << sizeof(dynamicArr) << " bytes" << endl;

    // Deallocating dynamic memory
    delete[] dynamicArr;
}

void demonstrateTypeCastingPointer() {
    char *ch;
    int l = 65;
    ch = (char *)&l;
    cout << "ch = " << *ch << endl; // Output: ch = A
}

int main() {
    demonstrateReferenceVariable();
    demonstrateDynamicMemoryAllocation();
    demonstrateStaticVsDynamicMemory();
    demonstrateTypeCastingPointer();
    return 0;
}
