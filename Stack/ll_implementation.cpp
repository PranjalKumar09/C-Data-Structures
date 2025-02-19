// STACK IMPLEMENTATION  USING LL
#include <iostream>
using namespace std;

class stack{
    int data, stackSize;
    stack *top, *next;
public:
    stack() : data(0), stackSize(0), top(nullptr), next(nullptr) {}
    stack(int x): data(x), stackSize(1), top(this), next(nullptr) {}

    void stackPush(int x){
        stack *element = new stack(x);
        stackSize++;
        element->next = top;
        top = element;
    }
    
    int stackPop(){
        if (isEmpty()) return -1;
        int topData = top->data;
        stack *temp = top;
        top = top->next;
        delete temp;
        stackSize--;
        return topData;
    }
    
    int size() { return stackSize; }
    
    bool isEmpty() { return top == nullptr; }
    
    int stackPeek(){
        if (isEmpty()) return -1;
        return top->data;
    }
    
    void stackPrint(){
        stack *temp = top;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a stack object
    stack myStack;

    // Push elements onto the stack
    myStack.stackPush(5);
    myStack.stackPush(10);
    myStack.stackPush(15);

    // Print the stack
    cout << "Stack: ";
    myStack.stackPrint();

    // Pop an element from the stack
    cout << "Popped element: " << myStack.stackPop() << endl;

    // Peek at the top element of the stack
    cout << "Top element: " << myStack.stackPeek() << endl;

    // Print the size of the stack
    cout << "Size of stack: " << myStack.size() << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
