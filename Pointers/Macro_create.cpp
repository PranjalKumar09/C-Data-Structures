/* 
Macro Create => defined by a # directive in the program.
# define PI 3.14 
now doing any operation it wont changed 
No extra space allocated
No change in micro white it wont be and assigining


Type of Macros 
1) Object like Macro : simpe identifer replaced by code fragment
# define DATE 31

2) Chain Rule : Macro inside macro
#define SQUARE(x) ((x) * (x))
#define SUM_OF_SQUARES(a, b) (SQUARE(a) + SQUARE(b))

3) Multi Line Macro : End with '\' (backlash) to start new line
#define ELE 1, \ 
            2, \
            3, 


4) FUnction  Line : parehtesis () have right after name 
#define MIN(a, b) ((a) < (b) ? (a) : (b))





Macro advantage : 
* Increase Productivity
* Customization
* Consistency
* Effiecieny 
* Ease of use



Disadvantage 
* Security risks
* LImited funcitonality
* Compatiblity 
* Maintaince 
* Dependece















Global variable : single memory block 
                  variables shared between functions by reference  
local variable inside loops & inside funciton 
Intiliaze / Declare outside int main()
int n = 1;
void fn(){
    cout << n;
}
int main(){
    cout << n;
    fn();
}
Global (Bad Practice) it can change by assignation & function so use ref varaible its better than function

Global advantage is some time for passing value by refrence in funciton 



Inline function
*Used to reduce function call 
*Reduce function call overhead

main --> func : 
  ^         |
  |         |
  -----------

  
inline funtio_name(parameter){
    //code 
}


Disadvantage -:
Code become bulky 
Reduce Speed 
Time taken to copy code can huge
Too many inlines can increase the binary size and memory usage

1 line   -> Its will work in inlinre
2-3 line -> Its dependent on that 
>3 line  -> Not work  (nothing happen in inlinr )

Normal function start               Inline function
            |                              |
          start  ----                    start 
            |       |          ____________|________
          stop   <--           |                   |
                               |       myfunc      |
                               |___________________|
                                           |
                                          End


Inline * just like memory
       * No memory usage
       * No function call overhead
       * Improve excution time and speed 
       * Increase readblity

Inline funciton not works in * loop(for while , do while )
                             * fn contain static variable
                             * Recursive
                             * COntaine switch or goto 




Default function -> Default value to use in parameter 
                 -> If function calling doesn't pass an argument then default value used elese deafault ignored

void sum(int n1 = 90 ; int n2  = 0 )
            --left to right-->

Deafult value in parameter & argument 
assignment =>  <--right to left---





Constant variable :

Syntax -> const datatype variable_name = value
Now we cant change its value throughout program

* Assigned during intiliazation only else storing garbage values that cant be changed further

Static Varaible stored in permanent storage area
Local store in stack 





 */

#include <iostream>
using namespace  std ; 
// Macro Definition
#define PI 3.14


// Define a chained macro to calculate the square of a number
#define SQUARE(x) ((x) * (x))
// Define another macro that uses the SQUARE macro to calculate the sum of squares
#define SUM_OF_SQUARES(a, b) (SQUARE(a) + SQUARE(b))



// multi line macro 
#define ELE 1, \
            2, \
            3 \

// Function-like macro to find the minimum of two values
#define MIN(a, b) ((a) < (b) ? (a) : (b))



// Global Variable
int globalVar = 10;

// Inline Function
inline int add(int a, int b) {
    return a + b;
}

// Default Function
void displayNumber(int num = 42) {
    cout << "Number: " << num << endl;
}

// Constant Variable
const int CONSTANT_NUMBER = 5;

int main() {
    // Using Global Variable
    cout << "Global Variable: " << globalVar << endl;

    // Using Macro
    double radius = 5.0;
    double area = PI * radius * radius;
    cout << "Area of the circle: " << area << endl;

    // Using Inline Function
    int result = add(3, 4);
    cout << "Result of inline function: " << result << endl;

    // Using Default Function
    displayNumber(); // Using default value
    displayNumber(20); // Passing an argument

    // Using Constant Variable
    // CONSTANT_NUMBER = 7; // This line would result in a compilation error
    cout << "Constant Variable: " << CONSTANT_NUMBER << endl;


    int num1 = 5;
    int num2 = 3;

    // Use the chained macros
    int result_square = SQUARE(num1);
    int result_sum_of_squares = SUM_OF_SQUARES(num1, num2);

    // Display the results
    cout << "Square of " << num1 << " is: " << result_square << endl;
    cout << "Sum of squares of " << num1 << " and " << num2 << " is: " << result_sum_of_squares << endl;


    int values[] = {ELE};
    // Using the ELE macro
    cout << "Values: " << values << endl;

     // Using the MIN macro
    int minimum = MIN(num1, num2);

    // Display the result
    cout << "Minimum of " << num1 << " and " << num2 << " is: " << minimum << endl;

    return 0;
}
