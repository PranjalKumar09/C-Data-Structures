#include <bits/stdc++.h>
using namespace std;

/* 
RAIN WATER TRAP USING STACK

    in stack we will push index


    current is slow index

    condition is like upward ridge type (of while)
    after while loop stack  +  current  will like downward or normal straight 

       
                                         *
                         *               *   *       *
                 *       *   *       *   *   *   *   *   * 
             =============================================
             0,  1,  0,  2,  1,  0,  1,  3,  2,  1,  2,  1 

COLLECTED =>         1       1   2   1           1
total = 6

current = 0


current = 1
   top = 0
   st.top() = 0
   arr[top] = 0
   arr[current] = 1
   arr[st.top()] = 0
   stack = 0 

current = 2

current = 3
   top = 2
   st.top() = 2
   arr[top] = 0
   arr[current] = 2
   arr[st.top()] = 0
   stack = 2 1 

   top = 1
   st.top() = 1
   arr[top] = 1
   arr[current] = 2
   arr[st.top()] = 1
   stack = 1 

current = 4

current = 5

current = 6
   top = 5
   st.top() = 5
   arr[top] = 0
   arr[current] = 1
   arr[st.top()] = 0
   stack = 5 4 3 


current = 7
   top = 6
   st.top() = 6
   arr[top] = 1
   arr[current] = 3
   arr[st.top()] = 1
   stack = 6 4 3 

   top = 4
   st.top() = 4
   arr[top] = 1
   arr[current] = 3
   arr[st.top()] = 1
   stack = 4 3 

   top = 3
   st.top() = 3
   arr[top] = 2
   arr[current] = 3
   arr[st.top()] = 2
   stack = 3 

current = 8

current = 9

current = 10
   top = 9
   st.top() = 9
   arr[top] = 1
   arr[current] = 2
   arr[st.top()] = 1
   stack = 9 8 7 


current = 11



 */

void print_stacK(stack<int> st){
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int solve(vector<int>& arr) {
    stack<int> st;
    int ans = 0;
    int n = arr.size();
    
    for (int current = 0; current < n; ++current) {

        while (!st.empty() && arr[current] > arr[st.top()]) {
            int top = st.top();
            st.pop();
            
            if (st.empty()) break;
            
            int distance = current - st.top() - 1; // in this boundary are brick so not included
            int bounded_height = min(arr[current], arr[st.top()]) - arr[top]; // arr[top] is lowest line here 
            /* 
            arr[current]:  height of the current bar which acts as the right boundary.
            arr[st.top()]: After popping the stack, this is the height of the left boundary.
            arr[top]: height of the bar that was just popped from the stack. This bar is the "bottom" of the container formed between the left and right boundaries. */

            ans += distance * bounded_height;

        }
        st.push(current);
    }
    
    return ans;
}

int main() {
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = solve(arr);
    cout << "Amount of trapped rain water: " << result << endl;
    return 0;
}



