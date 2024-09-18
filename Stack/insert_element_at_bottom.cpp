/* 
INSERT ELEMENT AT BOTTOM
 */
#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int> &stk , int x){ // TC = O(N)   SC = O(N)
    if (stk.empty()) {
        stk.push(x);
        return;
    }
    int temp = stk.top();
    stk.pop();
    solve(stk, x);
    stk.push(temp);
}

void printStack(stack<int> stk){
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}


int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    printStack(stk);
    solve(stk,6);
    printStack(stk);
}