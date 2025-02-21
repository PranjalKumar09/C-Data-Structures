#include <iostream>
#include <stack>

using namespace std;


bool valid_parenthesis(string expression){
    


    stack <char> parenthesis;

    for (int i = 0; i < expression.length(); i++){
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{')  parenthesis.push(ch);
        else {
            if (!parenthesis.empty()){
                char temp = parenthesis.top();
                if ((ch == ')' && temp == '(') ||
                    (ch == ']' && temp == '[') ||
                (ch == '}' && temp == '{')  )
                    parenthesis.pop();
                else return false;}
                }
            }
        return parenthesis.empty();
}
int main() {
    cout << (valid_parenthesis("[()]{}{[()()]()}") ? "Balanced expression" : "Unbalanced expression") << endl;
    return 0;
}
