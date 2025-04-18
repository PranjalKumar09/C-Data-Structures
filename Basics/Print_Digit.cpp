
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>

using namespace std;




void print_digits(int n, vector<string> &digits_in_words) {
    if (n == 0) return;
    int digit = n % 10;
    print_digits(n / 10, digits_in_words);
    cout << digits_in_words[digit] << endl;
}

void faster_method(int n, vector<string> &digits_in_words){
    int temp = 0;
    while(n){
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    
    while(temp){
        cout << digits_in_words[temp % 10] << endl;
        temp /= 10;
    }
}

void print_digits2(int n, vector<string> &digits){
    if (!n) return;
    int digit = n % 10;
    print_digits2(n / 10, digits);
    cout << digits[digit] << " ";

}




int main(){
   vector<string> digits_in_words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
   int n = 3491;
//    print_digits(n, digits_in_words);
   faster_method(n, digits_in_words);
   return 0;


}