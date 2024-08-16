//reversing a number
#include<iostream>
using namespace std;


/*class Solution {                      
public:
    int reverse(int x) {
        long r=0;      // decleare r 
        while(x){
         r=r*10+x%10; // find remainder and add its to r
         x=x/10;     // Update the value of x
        }
        if(r>INT_MAX || r<INT_MIN) return 0; // check range if r is outside the range then return 0  
        return int(r);  // if r in the 32 bit range then return r
    }
}; */

int main(){
    int num, Answer = 0; 
    cout << "Enter the number ";
    cin >> num; cout << endl;
    cout << " Reversed number is "; 
    while  (num != 0 ){
        int digit = num % 10;
        Answer = Answer * 10 + digit;
        num /= 10;
    }
    cout << Answer;

    return 0;
}




