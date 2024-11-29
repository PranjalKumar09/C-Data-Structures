#include <iostream>
#include <stack>
using namespace std;

/* 
IMPLEMENTATION QUEUE USING STACK

    Method 1:  We will require 2 stack to solve this
        push: s1 -> s2
        pop : s1.pop() 




    Method 2:  at very few other than O(1)

    TC: O(1)  (amotised , at ver few other than O(1))
    SC: O(2N)
    _________________    
    |MyQueue         |
    |================|
    |input stack     |
    |stack stack     |
    |push(int) void  |
    |pop() int       |
    |top() int       |
    |size() int      |
    |================|
    


    push -> add x->input
    pop -> if output not empty output pop
           else input->oupput
                output.pop()
    top -> if output not empty 
            output.pop()
        else input.pop()

 */


class MyQueue{
public:
    stack <int> input , output;

    void push(int x)    {input.push(x);}
    int pop()           {
        if(output.empty())
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        int x = output.top();
        output.pop();
        return x;}
    int size() { return (output.size()+input.size());}

    int top() {
        if(output.empty())
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        return output.top();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue top: " << q.top() << endl; // should print 1
    cout << "Queue size: " << q.size() << endl; // should print 3

    cout << "Pop element: " << q.pop() << endl; // should print 1
    cout << "Queue top after pop: " << q.top() << endl; // should print 2
    cout << "Queue size after pop: " << q.size() << endl; // should print 2

    cout << "Pop element: " << q.pop() << endl; // should print 2
    cout << "Queue top after pop: " << q.top() << endl; // should print 3
    cout << "Queue size after pop: " << q.size() << endl; // should print 1

    cout << "Pop element: " << q.pop() << endl; // should print 3
    cout << "Queue size after all pops: " << q.size() << endl; // should print 0

    return 0;}