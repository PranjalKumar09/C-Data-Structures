#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
IMPLEMENTAT GET MINI USING OPTIMIZEDM TO SC 


int mini = INT_MAX;
mini = min(mini, curr);
using another stack


push : i/p -> normal push
           -> mini value 2nd stack

pop : we have to pop from both stack


TC : O(1) 
SC : O(n)

2nd Stack top answer



push -> overflow condition
     -> for input element  -> normal path
                           -> mini update
     -> else
            if (curr < mini)
                                     push(2*curr - mini) ; //mini is prev minimum while  (2*curr - mini) is  current minimum
                                     mini upadte                                                                |    
            else normal path                                                                                    | to make it
                                                                                                                | connecting
pop operation                                                                                                   |
    -> underflow condition                                                                                      |
    -> if curr > mini then normal pop                                                                           | 
    -> else                             mini = 2*mini - curr <---------------------------------------------------
                                        pop
    -> return mini

get mini -> return mini


INT_MAX (Intiliazed)
mini = min(mini , curr)

    
y = 2x - z
z = 2x - y
z = 2x - (2x - z)
 */ 



class Special{
    stack<int> st;
    int mini;

public:
    void push(int data){
        if (st.empty()) {
            st.push(data);
            mini = data;}
        else {
            if (data < mini) {   // 2 * smaller - bigger => even small than smaller
                st.push(2*data - mini);    
                mini = data;
            } 
            else st.push(data);
        }
    }
    int pop(){
        if (st.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        
        int curr = st.top();
        st.pop();
        if (curr > mini) return curr;
        else {
            int prev_mini = mini;
            mini = 2*mini - curr;
            return prev_mini;
        }
    }

    int top(){
        if (st.empty()) return -1;
        if (st.top() < mini) return mini;
        else return st.top();
    }

    bool is_empty(){
        return st.empty();}
    int get_mini(){
        if (st.empty()) return -1;
        return mini;
    }
};

int main() {
    Special specialStack;

    // Push some elements onto the stack
    specialStack.push(5);
    specialStack.push(3);
    specialStack.push(2);
    specialStack.push(7);

    // Print the current minimum element
    cout << "Current minimum: " << specialStack.get_mini() << endl;

    // Pop elements from the stack
    cout << "Popped element: " << specialStack.pop() << endl;
    cout << "Popped element: " << specialStack.pop() << endl;

    // Print the top element of the stack
    cout << "Top element: " << specialStack.top() << endl;

    return 0;
}