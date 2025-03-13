#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;



/* 
NEXT LARGEST ELEMENT 
====================

all same as next smaller    execpt: while (s.top() <= curr)

 */


void optimize(vector<int> &ip){
    stack<int> st;
    st.push(-1);
    vector<int> ans(ip.size(), -1); 
    for (int i = ip.size()-1; i >= 0; i--){
        int curr = ip[i];
        while (!st.empty() && st.top() <= curr) 
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(curr);
    }
    ip = ans;
}


void print_array(vector<int> &arr){
    for (int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
}



int main() {
    vector <int> ip = {2,1,5,6,2,3,1};
    print_array(ip);
    optimize(ip);
    print_array(ip);

    return 0;
}
