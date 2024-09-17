#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
INFIX TO POSTFIX 

infix is normal opetation in maths 

If operand add in Postfix expression
If operator -> If presendence more then push oprator
               If presendence less then pop more are equal presence & add in expression | then push operator 



Prescendence 
* /   |High
+ -   |Low
    ( -> push in stack
    ) -> keeping pop & store/print tille ) is found

Input: ((A + B) – C * (D / E)) + F
Output: AB+CDE/*-F+  

high presendence is  appearing in left side 
 */

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infix_to_postfix(string &str) {
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
            while (!s.empty() && prec(str[i]) <= prec(s.top())) {
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
    str = result;
}

int main() {
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix expression: " << expression << endl;
    infix_to_postfix(expression);
    cout << "Postfix expression: " << expression << endl;
    return 0;
}

