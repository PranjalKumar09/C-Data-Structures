#include <iostream>
#include <stack>

using namespace std;

/* 
    DELETE MIDDLE ELEMENT USING STACKS

              stack          size
        solve(input ,   0 ,     N)

 */

void solve(stack<int>& stack, int size, int count) {
    if (count == size / 2) {
        // Base case: Reached the middle of the stack
        stack.pop(); // Remove the middle element
        return;
    }
    
    // Recursive case: Remove elements until reaching the middle
    int num = stack.top(); // Store the top element
    stack.pop(); // Remove the top element
    solve(stack, size, count + 1); // Recursive call
    stack.push(num); // Push the element back after the recursive call
}


void print(stack<int> &abc){

    stack<int> abs = abc;

    while (!abs.empty()) {
        cout << abs.top() << " ";
        abs.pop();
    }
    cout << endl;
}





int main(){
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    print(stack);
    solve(stack , stack.size()  , 0 );
    print(stack);
    

    return 0;
}