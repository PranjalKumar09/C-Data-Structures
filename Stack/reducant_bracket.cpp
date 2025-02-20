#include <iostream>
#include <stack>
#include <queue>


using namespace std;

/* REDUCANT BRACKET

((a+b)) -> useless brackets       (a+b) -> useful brackets

Tc : O(n)
SC : O(1)



in char not push_back but push
   also not pop_back but pop  

 */


bool findReducantBrackets(string &s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else if (ch == ')'){
                bool isReducant = 1;
                while ( !st.empty()   && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') isReducant = 0;
                    st.pop();
                }
                if (isReducant) return 1;
                if (!st.empty() && st.top() == '(') st.pop();       
            }
    }
    return 0;
}




int main(){
    string s = "(a+(b)/c)";
    cout << findReducantBrackets(s) << endl;


}