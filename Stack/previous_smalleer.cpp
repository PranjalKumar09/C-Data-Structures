#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 

    PREVIOUS SMALLER ELEMENT 
    
        all same code just  this change (in optimize)
                     ________________________________
                    | for (int i = 0 ; i < n ; i++) |
                    --------------------------------


        and in brute_force all loops reversed in prev compared to next
 */

void brute_force(vector<int> &ip){
    // TC = O(n^2), SC = O(1)
    for (int i = ip.size()-1 ; i > -1 ; i--){
        int prev = -1;
        for (int j = i - 1 ; j > -1 ; j--)
            if (ip[j] < ip[i]){
                prev = ip[j];
                break;
            }
        ip[i] = prev;
    }
}


void optimize(vector<int> &ip){
    stack<int> st;
    st.push(-1);
    vector<int> ans(ip.size(), -1); 
    for (int i = 0; i < ip.size(); i++){
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
    vector<int> input = {1, 6, 4, 10, 2, 5};
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
