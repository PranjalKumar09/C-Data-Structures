/* 
Types of pointers
1. Null Pointer
    A pointer that points to nothing (0).
    Use when you don't want to assign any address yet.

2. Void Pointer (Generic Pointer)
    Can store the address of any data type, but must be typecasted before dereferencing.

void *p
int i = 10 ; // like this
*p = &i

3. Wild Pointer
    A pointer that is declared but not initialized. Points to garbage



4. Dangling Pointer
    Points to a memory location that has been freed or deleted.


5. Double Pointer
    Pointer to a pointer. Used in dynamic 2D arrays or function passing.


There are 3 common ways a pointer becomes dangling:
    Function returns local variable (goes out of scope)
    Memory is deallocated (delete or free)
    Pointer assigned to a variable that goes out of scope    






In array address can found of first index (0 index) by simply arr also by &arr[0]
arr[0] & *arr first index value of arr will print 
Array ->   *arr  |  *(arr + 1)    | *(arr + 2 ) .........    |      *(arr + n-1) 
Index ->    0    |      1         |      2      .........    |          n-1


arr[i] == *(arr + i) == i[arr] == *(i + arr)



*arr + 1 and *(arr + 1) are different 
arr[0]+1        arr[1]



arr[i]   =    *(arr + i)    <=>      i[arr]   = *(i+arr)


size of (*arr)     ->  4 (1st index)
size of  &arr      ->  8  (address)

 &arr = arr      {in case of array}

note but you can compare them it gives error 
however you can print both


int *p = arr[0];

&arr[0]  or   &arr   or arr      are same 

and different from  &p 


Symbol table content cant be changed 

arr += 1  ;// GIVES ERROR
but in ptr+=1 // + index






Character Array    <Its different from arr>

char ch[5] = "abcde";
cout << ch // abcde


char *p = &ch[0];
cout << p; //abcde


In single
char temp = 'z'
char *p2 = &temp;
cout << p2; //address will come 



Char a[10] = "geek"     |    char *P = "geek"
a is array              |    p is pointer variable
size of a = 10 bytes    |    size of p = 4 bytes
a and &a same           |    p and &p are different
a++ in invalid          |    p++ is valid
a[0] = 'k'   VALID      |    p[0] ="k" INVALID

When printing a single char using a pointer (e.g., char* p = &ch;), it may print not just the character but everything from that address onward until it hits a null terminator (\0).
Since a single char doesn’t have a null terminator by default, this can cause unexpected output or garbage values.

Avoid: char *c = "abcde" // (alocate any memory to it)

Print Address: cout << *p ; // in single char 
here it is not array it is pointer 


int getsum (int arr[]) // *arr same // *arr[]  , different
cout << &p ; (array size)
Address is passing 

We can send part of arr in function
                  __________________________________________
                 |                                          |
 _____ _____ ____| _____ _____ _____ ____________________   |----> arr + 3 
|     |     |    ||     |     |     |      ......        |  |
|  1  |  2  |   3||     |     |     |      ......     n  |  |   
|_____|_____|____||_____|_____|_____|______......________|  |    
                 |                                          |
                 |__________________________________________|

cout << st[i] << *(st + i) << i(st); // all will print same

cout << *(st) + i ; // print ascii code of st+i (like of A = 65)


char_arr + i = ptr + i  // subarray                  
char_arr[i] = *(ptr[i]) // element                     


 */


#include <iostream>
using namespace std;

int main()
{
    // ------------------ NULL Pointer ------------------
    int* p1 = NULL;  // or int* p1 = 0;
    cout << "NULL Pointer: " << p1 << endl; // Output: 0 (null address)
    // cout << *p1 << endl; // SEGMENTATION FAULT - dereferencing NULL

    // ------------------ Wild Pointer ------------------
    int* p2; // Wild pointer (uninitialized)
    // cout << p2 << endl;  // Prints garbage address
    // cout << *p2 << endl; // Undefined behavior (may print garbage or crash)

    // ------------------ Pointer with Initialization ------------------
    int a = 10;
    int* p3 = &a;
    cout << "Value at p3: " << *p3 << endl; // Output: 10

    // ------------------ Void Pointer ------------------
    void* vp;
    int b = 20;
    vp = &b;
    // cout << *vp << endl; // ERROR: Cannot dereference void*
    cout << "Void pointer (after casting): " << *(int*)vp << endl; // Correct

    // ------------------ Pointer with Array ------------------
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "Pointer and Array Equivalence:" << endl;
    cout << (arr[0] == *(arr)) << endl;     // 1
    cout << (arr[1] == *(arr + 1)) << endl; // 1
    cout << (arr[2] == *(arr + 2)) << endl; // 1
    cout << (arr[3] == *(arr + 3)) << endl; // 1
    cout << (arr[4] == *(arr + 4)) << endl; // 1

    // Garbage values (out of bounds)
    // cout << *(arr + 5) << endl;
    // cout << arr[5] << endl;

    // arr[i] == *(arr + i) == i[arr] == *(i + arr)
    cout << "arr[2]: " << arr[2] << " == *(arr + 2): " << *(arr + 2)
         << " == 2[arr]: " << 2[arr] << " == *(2 + arr): " << *(2 + arr) << endl;

    // Demonstrating *arr + i vs *(arr + i)
    cout << "*arr + 1 = " << *arr + 1 << endl;       // arr[0] + 1 = 10 + 1 = 11
    cout << "*(arr + 1) = " << *(arr + 1) << endl;   // arr[1] = 20

    // ------------------ Size of pointers and arrays ------------------
    cout << "sizeof(&arr) = " << sizeof(&arr) << endl; // 8 (address of entire array)
    cout << "sizeof(*arr) = " << sizeof(*arr) << endl; // 4 (int element size)

    // Comparing &arr and arr
    cout << "Address (&arr): " << &arr << " | arr: " << arr << endl;

    // arr += 1; // Error: Cannot modify array name (const pointer)
    // But we can do:
    int* ptr = arr;
    ptr += 1; // Valid: pointer arithmetic

    return 0;
    }