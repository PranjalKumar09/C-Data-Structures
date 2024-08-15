#include <iostream>
#include <cstring>
using namespace std;




int main(){
    string str1 = "hello";
    string str2 = "bye world";
    
    cout << str1 + str2 << endl; // hellobye world
    str1.append(str2);
    cout << str1;// hellobye world

    return 0;
}

