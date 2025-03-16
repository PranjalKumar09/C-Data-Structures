#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
PREFIX TO INFIX CONVERSION

* Read reverse order (right to left)
* If operand then push
* If symbol is operator then pop two operations from stack
string = operand1 + operator + operand2
         (first popped)        (last popped)
* Repeats above steps
* Return at end  


General for all
TC = O(N)
SC = o(N)

 */ 



bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string solve(string input){
    stack<string> st;
    for (int i = input.size()-1 ;i >= 0 ;i--){
        if (is_operator(input[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + input[i] + op2 + ")");  // converting char to string


        }
        else
            st.push(string(1,input[i]));
    }
    return st.top();
}


int main() {
    string prefix_expression;
    cout << "Enter a prefix expression: ";
    cin >> prefix_expression;

    string infix_expression = solve(prefix_expression);
    cout << "Infix expression: " << infix_expression << endl;

    return 0;
}