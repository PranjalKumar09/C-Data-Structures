/* 
Types of pointers
Null -> If we dont have address to be arranged to be assigned we can use NULL 
int *p = NULL ; \\ OR 0 
priting p will give 0 while printing *p will give segmenation fault beacause how we can print value in no address


Void -> Hold adress of any type & can be typeroted to any type (Generic )
void *p
int i = 10 ; // like this
*p = &i


Wild -> when declared not initialized but when it no longer remain wild pointer 

Double Array 
Danging -> pointing location (freed on deleted )



THREE WAYS
deloation of memory 
function call      ->      


int *p 
//code 
p =  ... 
variable out of scope




In array address can found of first index (0 index) by simply arr also by &arr[0]
arr[0] & *arr first index value of arr will print 
Array ->   *arr  |  *(arr + 1)    | *(arr + 2 ) .........    |      *(arr + n-1) 
Index ->    0    |      1         |      2      .........    |          n-1





*arr + 1 and *(arr + 1) are different 
arr[0]+1        arr[1]



arr[i]   =    *(arr + i)    <=>      i[arr]   = *(i+arr)


size of (*arr)     ->  4 (1st index)
size of  &arr      ->  8  (address)

 &arr = arr      {in case of array}

// note but you can compare them it gives error 
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


In single char char temo = 'z
char temp = 'z'
char *p2 = &temp;
cout << p2; //address will come 






Char a[10] = "geek"     |    char *P = "geek"
a is array              |    p is pointer variable
size of a = 10 bytes    |    size of p = 4 bytes
a and &a same           |    p and &p are different
a++ in invalid          |    p++ is valid
a[0] = 'k'   VALID      |    p[o] ="k" INVALID



In single char it goes to address & zee when null case then till null casr it prints till null case (normally 1 size)


Avoid: char *c = "abcde" // (alocate any memory to it)

Print Address: cout << *p ; // in single char 
here it is not array it is pointer 


int getsum (int arr[]) // *arr[]
cout << &p ; (array size)
Address is passsing 

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
    // int *p = NULL;
    // cout << p << " "  << endl; // 0 

    // cout << *p ;  //Segmentation fault (core dumped) Error





    // int *p ;
    // cout << p; // print random memory 0x7fd6be51e934

    // cout << *p ; //puts random garbage value




    // implemeting pointers in arrays 
    int arr[5] = {10 , 20 , 30 , 40 , 50};
    // cout << (arr[0]  == *(arr)  )     ; // 1 
    // cout << (arr[1]  == *(arr + 1) )  ; // 1 
    // cout << (arr[2]  == *(arr + 2) )  ; // 1 
    // cout << (arr[3]  == *(arr + 3) )  ; // 1 
    // cout << (arr[4]  == *(arr + 4) )  ; // 1 

    // cout << *(arr+5) ; // both store garbage values 
    // cout << arr[5]; // store garbage values

    // note > arr[i]   =    *(arr + i)   =    i[arr]   = *(i+arr) all 4  are equals


    // cout << *arr + 1 ; // 11
    // note > *arr + i  != *(arr + i)         *arr + i => arr[0] + i           *(arr+i) = arr[i]



    // cout << sizeof(&arr) << endl; // 8
    // cout << sizeof(*arr) << endl; // 4


    
    // cout << &arr << arr << endl; // each time different address , however there both address is same



    // arr+=1 ; // ERROR
    


    return 0;
}