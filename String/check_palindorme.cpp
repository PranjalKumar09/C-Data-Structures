
#include <iostream>

using namespace std;

bool check_palindrome(string word){
    int start = 0 ,  end = word.length() - 1;
    while(start < end)    if (word[start++] !=  word[end--]) return 0;
    return true;
}

bool check_palindrome_recursion(string word , int start, int end){
    if (start >=end) return true; 
    if (word[start]!= word[end]) return false;
    return check_palindrome_recursion(word, start+1, end-1);
}

int main(){
    cout << endl;

    string word;
    cout << "Enter a word: ";
    cin >> word; cout <<  endl;

    check_palindrome(word) ? cout << "Palindrome" : cout << "Not palindrome";

    // check_palindrome_recursion(word, 0 ,word.length()) ? cout << "Palindrome" : cout << "Not palindrome";
    

    cout << endl;
    return 0;
}