#include <iostream>
#include <stack>
#include <queue>


using namespace std;

/* 
    HOW MUCH MINIMUM BRACKET CHANGE TO MAKE VALID BRACKET


odd no of character always false



a-> opening {      b-> closing }

a+1 + b+1  = ans
---   ---
 2     2



Tc : O(n)
SC : O(n)
 */




// 
int solve(string ip){
    if (ip.length() % 2 == 1) return -1;
    stack<char> st;
    int a = 0 , b = 0;
    for (int i = 0; i < ip.length(); i++){
        char ch = ip[i];
        if (ch == '(') st.push(ch);
        else {
            if (!st.empty() && st.top()=='(') st.pop();
            else st.push(ch);
        }}
    while(!st.empty() ){
        if (st.top()=='(')  b++; 
        else  a++;
        st.pop();
    }
    return (a+1)/2 + (b+1)/2 ;
    
}

int main(){
    string ip = "()()() " ;
    cout << solve(ip) << endl;

    return 0;

}