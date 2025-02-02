#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
EVALUATION OF POSTFIX EXPRESSION

Iterate from left to right & keep storing opeand in stack once operator is recived, pop topmost two elements & evaluates then & push result in stack again.

 
 */

int solve(string str){
    // remove white spaces
    while (str.find(" ")!= string::npos)
        str.erase(str.find(" "), 1);
    


    if (str.length()  < 1) return -1;
    stack<int> st ; 
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= '0' && str[i] <= '9')
            st.push(str[i] - '0');
        
        else{
            int var1 = st.top();
            st.pop();
            int var2 = st.top();
            st.pop();
            switch(str[i]){
                case '+':
                    st.push(var1+var2);
                    break;
                case '-':
                    st.push(var2-var1);
                    break;
                case '*':
                    st.push(var2*var1);
                    break;
                case '/':
                    st.push(var2/var1);
                    break;
            }
        }
    }
    return st.top();
}


int evaluate(vector<string>& arr) {
    stack<int> st;
    for (auto &s : arr) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (s == "+") st.push(a + b);
            else if (s == "-") st.push(a - b);
            else if (s == "*") st.push(a * b);
            else st.push(a / b);
        } else st.push(stoi(s));
    }
    return st.top();
}

int main(){
    string str = "2 3 1 * + 9 -";
    cout << solve(str) << endl;

}