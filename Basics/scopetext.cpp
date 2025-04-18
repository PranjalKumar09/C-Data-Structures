#include<iostream>
using namespace std;

int main(){
    int outside  = 3;
    if (true){
        int outside = 5;
        cout << outside << endl;}       //5
    cout << outside << endl;            //3
    
    if (1){
        int temp = 5;
        cout << temp << endl;  }       //5
    //cout << temp;                     //error

    if (true){
        int b = 5;
        cout << b << endl;
    }
    int  b = 1;
    cout << b << endl;
    //int b  = 3; //error because of redifination
    cout << b << endl;
} 