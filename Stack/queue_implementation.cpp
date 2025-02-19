// IMPLEMENTATION OF STACK BY QUEUE 
#include <iostream>
#include <queue>

using namespace std;

class Stack{
    queue <int> q;
    public:
        void Push(int x){
            

            // queue = 1 , 2 , 3       x = 4
            int s = q.size(); // size = 3
            q.push(x);  // queue = 1 , 2 , 3 , 4
            for (int i = 0; i < s; i++) {
                q.push(q.front());
                q.pop();}
        // queue = 4 , 1 , 2 , 3
        }

        int Pop(){
            int n = q.front();
            q.pop();
            return n;
        }

        int Top(){return q.front();}
        int size(){return q.size();}
        bool empty(){return q.empty();}
        void Print() {
            queue<int> temp = q; // Create a temporary queue to store elements
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }

};
int main() {
    Stack myStack;

    // Push elements onto the stack
    myStack.Push(5);
    myStack.Push(10);
    myStack.Push(15);

    // Print the stack
    cout << "Stack: ";
    myStack.Print();

    // Pop an element from the stack
    cout << "Popped element: " << myStack.Pop() << endl;

    // Print the top element of the stack
    cout << "Top element: " << myStack.Top() << endl;

    // Print the size of the stack
    cout << "Size of stack: " << myStack.size() << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    return 0;
}