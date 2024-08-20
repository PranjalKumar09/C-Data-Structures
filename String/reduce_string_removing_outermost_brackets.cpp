/*  
in first method  it is more efficient
count intliaze with 0
also here ofr loop is char c: like not int
it uses one count if "(" catched increase it if ")" decreas count
and in "(" check count whether it will more than zero if ")" check than ")" then check whether it is more than 1 


in second method set start , opencount , closecount all 3 is 0
if both count are equal then result += substring from start + 1 is starting postion and  i -start - 1 is size 






 */

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<stack>


using namespace std;




string method1(string str){
    int count = 0; 
    string ans = "";
    for (char c : str){
        if (c == '(' && count++ > 0 )// it will zero because it is balanced 
            ans += c;
        else if (c == ')' && count-- > 1) // it will one because last count-- not performed
            ans+=c;
    }
    return ans;
}

string method2(string str){
    int start = 0, opencount = 0, closecount = 0;
    string result ="";
    for (int i = 0 ; i < str.length(); i++){
        char current = str[i] ;
        if (current == '(' ) opencount++;
        else if (current == ')') closecount++;
        if (opencount == closecount){
            result += str.substr(start + 1, i  - start - 1 ); // str.substr(start , size)
            start = i+1;
        }
    }
    return result;
}

 int main(){

    cout << endl ;

    string str = "(()())(())()";
    cout << method1(str) << endl << method2(str) << endl;
    

    return 0;
}

 