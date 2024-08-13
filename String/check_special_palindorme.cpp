// we have to compare only number and lowercase only 

/* 
You are using start++ and end-- directly in the if condition, which means the increment or decrement will happen after the condition is evaluated. This may lead to incorrect comparisons.
 */
#include <iostream>

using namespace std;


bool is_alphanumeric(char ch){
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
}



bool check_special_palindrome(const string& word) {
    int start = 0, end = word.length() - 1;
    while (start < end) {
        if (!is_alphanumeric(word[start])) {
            start++;
            continue;
        }
        if (!is_alphanumeric(word[end])) {
            end--;
            continue;
        }
        if (word[start++] != word[end--])
            return false;
    }
    return true;
}


int main(){
    cout << endl;

    string word;
    cout << "Enter a word: ";
    cin >> word; cout <<  endl;

    check_special_palindrome(word) ? cout << "Palindrome" : cout << "Not palindrome";
"Palindrome" ; cout << "Not palindrome";
    

    cout << endl;
    return 0;
}