/* 
static number variables -> static variables initialized only once 

only one copy thus also called class variable


Static function: can only acess by other static variables/functions present in same class they called thorough.
syntax:
static void func()   //static function making 
class 1::fnc()       //function callling





 */

#include <iostream>
using namespace std;

void test(){
    static int x = 1;
    x = ++x;
    int y = 1;
    y = ++y;
    cout << "x = " << x << " y = " << y << endl;
}

int main(){
    test(); // x = 2 y = 2
    test(); // x = 3 y = 2

    return 0;
}