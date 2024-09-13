// ARRAY IMPLEMENTATION     (FIXED SIZE)
#include <iostream>
using namespace std;

class stack{
    int size , top, *arr;

    public:
        stack(int length) : size(length) , top(-1) , arr(new int[length]){}

        void push(int element){
            if (top < size - 1){ // as we setted the top to -1 & it is postfix below
                top++;
                arr[top]  = element;
            }
            else cout<<"Stack overflow"<<endl;
        }

        int pop(){
            if (top >= 0) {
                
                return arr[top--];}
            else cout<<"Stack underflow"<<endl;   
            return -1; 
        }

        int topValue(){
            if (top >= 0 && top < size) // here not need to add condition top<size because it will always statisfy
                return arr[top];
            cout<<"Stack Empty"<<endl;
            return -1;
        }
        bool isEmpty() {return top<0;}
        int stackSize() {return top+1;}



};


int main(){
    stack s(5);

    // Push some elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // Attempt to push more elements to trigger stack overflow
    s.push(6);

    // Print the size of the stack
    cout << "Stack size: " << s.stackSize() << endl;

    // Print the top element of the stack
    cout << "Top element: " << s.topValue() << endl;

    // Pop elements from the stack until it's empty
    cout << "Popping elements: ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    // Attempt to pop more elements to trigger stack underflow
    s.pop();

    return 0;
}