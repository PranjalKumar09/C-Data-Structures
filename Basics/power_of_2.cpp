#include <iostream>
#include <stdint.h>


using namespace std;

int main(){
    int num, count = 1; // count for method 1
    cout << "Enter the number ";
    cin >> num;
    // Method 1 
    // while ( num<INT16_MAX && num > 0 ){
    //     if (count==num){
    //         cout<<"Power of 2 ";
    //         return 0;}
    //     count *= 2;       
    //     }
    // cout<<"Not power of 2";
    //  Method 2
    if (num<=0 && !(num & (num-1))){
        cout<<"Not power of 2";
        return 0;
    }
    cout << "Power of 2";


    return 0;
}