#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
POSTFIX TO PREFIX
    read in general order   (left to right) 
    if operand the push
    if operator then pop two operands
    string = operator + opeand1 + operand2 
                                    
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
            string result = input[i] +  op1 + op2; // Concatenate in the order: op1, op2, input[i]
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
    string postfix_expression;
    cout << "Enter a postfix expression: ";
    cin >> postfix_expression;

    string prefix_expression = solve(postfix_expression);
    cout << "Prefix expression: " << prefix_expression << endl;

    return 0;
}