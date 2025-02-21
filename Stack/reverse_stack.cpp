#include <iostream>
#include <stack>
#include <queue>


using namespace std;

/* 
    REVERSE  STACK 
*/


// method 1 

void InsertAtBottom(stack<int> &stk , int x){ // TC = O(N)   SC = O(N)
    if (stk.empty()) {
        stk.push(x);
        return;
    }
    int temp = stk.top();
    stk.pop();
    InsertAtBottom(stk, x);
    stk.push(temp);
}

void ReverseStack(stack<int>& st ){
/* 
7       7   3
5           4
3           5
4  =>       
 */
    if(st.empty()){
        return;
    }
    int temp = st.top(); // first keep stack-top at side (means store it in temp)
    st.pop();
    ReverseStack(st); // recursively reverse remaining
    InsertAtBottom(st,temp); // while coming back do insertatbottom
}


// method 2   using stack reverse by queue

void ReverseStack2(stack<int>& st){
    queue<int> qt ;
    while(!st.empty()){
        qt.push(st.top());
        st.pop();
    }
    while(!qt.empty()){
        st.push(qt.front());
        qt.pop();
    }
}


void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printStack(st);
    
    
    ReverseStack2(st);
    printStack(st);
    ReverseStack](st);
    printStack(st);


     return 0;

}