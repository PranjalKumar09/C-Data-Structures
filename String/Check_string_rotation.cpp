/* 
string :: npos; is  last postion 




*/
#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

bool string_rotatoion(string s1, string s2){
    if (s1.length() != s2.length()) return false;
    return (s1+s1).find(s2) != string :: npos;

}

int main(){
    cout << endl;

    string s1 = "ABCD" , s2 = "ACBD";
    cout << string_rotatoion(s1, s2) << endl;

    cout << endl;
    return 0;
}