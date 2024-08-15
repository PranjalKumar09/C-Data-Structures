
/* 

In the palindrome_every_word function, the condition if (word[i] == " ") is comparing a character (word[i]) with a string literal (" "), which is incorrect. You should compare with a character literal (' ') instead.

Also remember to put else if (i == word.length()-1){
            do_reverse(word,start,i);}
for not mising last word in case user forget to enter space here */
#include<iostream>

using namespace std;

void  do_reverse(string &word ,int start ,int end){
    while(start < end)    swap(word[start++],word[end--]);
}

void reverse_every_word(string &word){
    int start = 0;
    for (int i = 0; i < word.length(); i++){
        if (word[i] == ' '){
            do_reverse(word,start,i-1);
            start = i+1;
        }
        else if (i == word.length()-1){
            do_reverse(word,start,i);
        }
}}



int main(){
    cout << endl;

    string word;
    cout << "Enter a word/sentence: ";
    getline(cin , word); cout << endl;


    palindrome_every_word(word);

    
    cout  << word << endl;
    
    cout << endl;
    return 0;
}