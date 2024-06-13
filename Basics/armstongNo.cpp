#include <iostream>
using namespace std;

bool ArmstrongNumber(int num){
    int sum = 0;
    while (num) 
    {
        int remainder = num % 10;
        sum += num % remainder;
        num = num/10;
    }
    return sum==num;    
}

int main(){
    int n;
    cout << "Enter the number: " ;
    cin >> n; cout << endl;
    ArmstrongNumber(n) ? cout << "Number is Armstrong number" : cout << "Number is not Armstrong number" ;

    cout << endl;


    return 0;
}