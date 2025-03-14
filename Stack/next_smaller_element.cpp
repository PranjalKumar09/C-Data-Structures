#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 

    NEXT SMALLER ELEMENT 

    next  do trainsitoin from last to first in for loop optimized

    i/p : [13,7,6,12]
    o.p : [7,6,-1,-1]
    

    first element smaller than i on right side 

              stack          size
        solve(input ,   0 ,     N)
    
    13 7 6 12  => 7
       7 6 12  => 6
         6 12  => -1
           12  => -1
           
 */
void brute_force(vector<int> &ip){
    // TC  = O(n2)     sc = O(1)
    for (int i = 0 ; i < ip.size() ; i++){
        int next = -1;
        for (int j = i + 1 ; j < ip.size() ; j++)
            if (ip[i] > ip[j]){
                next = ip[j];
                break;}
        ip[i] = next;
    }
}

void optimize(vector<int> &ip){
    stack<int> st;
    st.push(-1);
    vector<int> ans(ip.size(), -1); 
    for (int i = ip.size()-1; i >= 0; i--){
        int curr = ip[i];
        while (!st.empty() && st.top() >= curr) 
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(curr);
    }
    ip = ans;
}

int main() {
    vector<int> input = {5, 2, 8, 7, 1};
    cout << "Input vector: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    optimize(input);

    cout << "Output vector: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
