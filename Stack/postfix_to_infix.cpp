#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
POSTFIX TO INFIX 
    Left to right
    Rest same as prifx to infix
                                    
*/ 





bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string solve(string input){
    stack<string> st;
    for (int i = 0 ;i < input.size() ;i++){
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
    string posftix_expression;
    cout << "Enter a postfix expression: ";
    cin >> posftix_expression;

    string infix_expression = solve(posftix_expression);
    cout << "Infix expression: " << infix_expression << endl;

    return 0;
}