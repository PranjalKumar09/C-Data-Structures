/* 
If address goes in function then only change in value possible in actual int , arr etc

int **ptr2 = &ptr1    Double ptr

value of *ptr1 and *pr2 and value_int will same

Value of &value , ptr1 , *ptr2 will same

&ptr1 = ptr2 = &&ptr1  double ptr

**ptr2 += 1
*ptr2 +=1 // will increase value int by 1
*ptr2 +=1 // will increase value ptr1 by 4byte

int *p = 0;                 
int first = 110;             
*p = first // Wrong way     |   p = &first ; 



*/


#include <iostream>

using namespace std;

int main() {
    int value_int = 5;
    int *ptr1 = &value_int;
    int **ptr2 = &ptr1;

    cout << "Initial value_int: " << value_int << endl;
    cout << "Initial *ptr1: " << *ptr1 << endl;
    cout << "Initial **ptr2: " << **ptr2 << endl;
    cout << "Initial &value_int: " << &value_int << endl;
    cout << "Initial ptr1: " << ptr1 << endl;
    cout << "Initial *ptr2: " << *ptr2 << endl;

    **ptr2 += 1;
    cout << "After **ptr2 += 1, value_int: " << value_int << endl;

    *ptr1 += 1;
    cout << "After *ptr1 += 1, value_int: " << value_int << endl;

    (*ptr2)++;
    cout << "After *ptr2 += 1, ptr1: " << ptr1 << endl;

    int *p = nullptr; // initialize p to null pointer
    int first = 110;
    p = &first; // assign the address of first to p

    cout << "After assigning address of first to p, *p: " << *p << endl;

    return 0;
}

