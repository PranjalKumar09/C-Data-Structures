#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display_result(int num , vector<long> &result){
    cout << "Factorial of " << num << " is ";
    for(int i=0;i<result.size();i++)cout << result[i] ;
    
}

void factorial_of_large_number(int num){
    if (num < 0){
        cout << "Factorial of negative number not supported" << endl;
        return;
    }
    vector<long> factorial;
    factorial.push_back(1);
    if (num <= 1){
        display_result(num , factorial);
        return; }
    for (int i = 1 ; i <= num ; i++){
        int carry = 0;
        for (int j = 0; j < factorial.size(); j++){
            int multiply_result = factorial[j] * i + carry;
            factorial[j] = multiply_result % 10;
            carry = multiply_result / 10;}
        if (carry > 0)
            factorial.push_back(carry);   
    }
    reverse(factorial.begin(), factorial.end());
    display_result(num, factorial);
}

int main(){
    cout << endl;

    int num = 100;
    factorial_of_large_number(num);
    
    
    cout << endl;
    return 0;
}