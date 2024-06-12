#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int num, count = 0; // count for method 1
    cout << "Enter the number ";
    cin >> num; cout << endl;
    cout<< " No of digits are "; 
    // Method 1
    // while (num!=0){
    //     num= int(num/10);
    //     count++;}
    // cout<<count;
    // Method 2
    // string str = to_string(num);
    // cout << sizeof(str)/8 ;
    // Mehtod 3
    // cout << floor(log10(num))  + 1;
    return 0;
}