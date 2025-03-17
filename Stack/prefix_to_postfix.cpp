#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
PREFIX TO POSTFIX
    read in reverse order 
    if operand the push
    if operator then pop two operands
    string = opeand1 + operand2+ operator
                                    
*/ 





bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string solve(string input){
    stack<string> st;
    for (int i = input.size()-1; i >= 0; i--){
        if (is_operator(input[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string result = op1 + op2 + input[i]; // Concatenate in the order: op1, op2, input[i]
            st.push(result);
            // cout << "Stack after processing operator " << input[i] << ": " << result << endl;
        }
        else {
            st.push(string(1, input[i])); // Push operand onto the stack
            // cout << "Stack after pushing operand " << input[i] << ": " << st.top() << endl;
        }
    }
    return st.top();
}


int main() {
    string prefix_expression;
    cout << "Enter a prefix expression: ";
    cin >> prefix_expression;

    string postfix_expression = solve(prefix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;

    return 0;
}