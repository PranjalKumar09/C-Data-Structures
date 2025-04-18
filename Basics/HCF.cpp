#include<iostream>
using namespace std;


    int gcd(int num1 , int num2){
        num1 = abs(num1); // Ensuring negative no
        num2 = abs(num2);

        if (min(num1,num2) < 2)    return min(num1,num2);

        while (num2){
            int remainder =  num1 % num2;
            num1  = num2;
            num2  = remainder;  
            }
        return num1;
    }


int main(){
    int num1 , num2;
    cout<< "Enter two numbers for gcd : ";
    cin >> num1 >> num2 ; 
    cout <<"GCD is " << gcd(num1,num2);

    


    return 0 ;
}