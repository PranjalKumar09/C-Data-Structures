#include <iostream>
#include <stack>
#include <queue>


using namespace std;

/* 
SORT A STACK
1) First remove each element 
2) Then add each in sorted way

Tc : O(n^2)
SC : O(n)
 */

void insertSorted(stack<int>& st, int temp){
    if (st.empty() || temp > st.top()){
        st.push(temp);
        return;
    }
    int temp2 = st.top();
    st.pop();
    insertSorted(st, temp);
    st.push(temp2);
}


void sort(stack <int> &st){
    if (st.empty()) return;
    int temp = st.top();
    st.pop();
    sort(st);
    insertSorted(st, temp);
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
    st.push(12);
    st.push(2);
    st.push(31);
    st.push(4);
    st.push(25);
    printStack(st);
    
    
    sort(st);
    printStack(st);
     return 0;

}