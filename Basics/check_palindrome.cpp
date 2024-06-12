// check palindrome 
// 1-> by chceking str = to reverse of string
// 2 -> by checking each from start to end

#include<iostream>
#include<string>

using namespace std;

bool CheckreverseStr(string& old_str){
    string str = old_str;
    int length = old_str.length();
    for (int i = 0; i < length/2 ; i++){
        swap(str[i] ,str[length-i-1]);}

    return str == old_str;
}

bool Method2(string& old_str){
    int length = old_str.length();
    for (int i = 0; i < length/2 ; i++)
        if (old_str[i] != old_str[length-i-1])
            return false;

    return true;
}

int main(){
    cout << "Enter the string :" ;
    string str;
    getline(cin , str); cout <<  endl;
    CheckreverseStr(str) ? cout << "Palindrome " : cout << "Not palindrome" ;
    cout<< endl;
    Method2(str) ? cout << "Palindrome " : cout << "Not palindrome" ;
    
    return 0;
}