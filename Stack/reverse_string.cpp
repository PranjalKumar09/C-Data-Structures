#include <iostream>
#include <stack>

using namespace std;

/* 
    REVERSE A STRING USING STACK 

        TC: O(N)
        SC: O(N)
 */

 string reverse_string(string &str){
    stack<char> s;
    for(int i=0; i<str.length(); i++)
        s.push(str[i]);
    str = "";

    
    while(!s.empty()){
        str.push_back(s.top());
        s.pop();
    }
    return str;
}

int main(){
    string str = "abcdefghijklmnopqrstuvwxyz";
    cout << reverse_string(str) << endl;
    return 0;

}