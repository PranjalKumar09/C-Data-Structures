#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;
/* 
INFIX TO PREFIX 


remember this fn here looks like infix to postfix but it is not because in infix to postfix there is no check in operator case but in this fn 
     while (!s.empty() && (prec(str[i]) <= prec(s.top()) && str[i]=='^' )||  prec(str[i]) < prec(s.top())   ) {
                result += s.top();
                s.pop();



reverse the string 
 */

int prec(char c) {
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string fn(string str) {
    str = "("+str+")";

    stack<char> s;
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            result += ch;
        else if (ch == '(')
            s.push(ch);
        else if (ch == ')') {
            while (s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        } else {
            
            while (!s.empty() && (prec(str[i]) <= prec(s.top()) && str[i]=='^' )||  prec(str[i]) < prec(s.top())   ) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}
string infix_to_prefix(string infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' and ')' characters
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert the modified infix expression to postfix
    string prefix = fn(infix);

    // Step 4: Reverse the postfix expression
    reverse(prefix.begin(), prefix.end());

    return prefix; // Return the prefix expression
}

int main() {
    string expression = "x+y*z/w+u";
    cout << "Infix expression: " << expression << endl;
  
    cout << "Prefix expression: " << infix_to_prefix(expression) << endl;
    return 0;
}

