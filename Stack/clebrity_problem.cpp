#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;



/* 
CELEBRITY PROBLEM 
====================

 Everyone know celebrity , celebrity knows none ignore digonal element



 BRUTE FORCE 
    TC = o(N^2) 

    for (i = 0 -> n-1)
        row
        for col



 METHOD 2
    put all element ni srack in any order 
    if upper one knows anybody then pop else push in last left one should potential candiate , check it
 */

// grid[a][b] means a knows b

int method2(vector<vector<int> > & grid){
    stack<int> st;
    for (int i = 0 ; i < grid.size() ; i++) st.push(i);
    while (st.size()>1){
    cout << " running " << endl;
        int top = st.top();
        st.pop();
        if (st.size() == 0) break;
        int top2 = st.top();
        st.pop();
        if (grid[top][top2]) st.push(top2);
        else st.push(top);
    }
    int candiate = st.top();
    st.pop();
    for (int i = 0 ; i < grid.size() ; i++)
        if (i != candiate  && (grid[candiate][i] || !grid[i][candiate]))
            return -1;
    return candiate;
        
    
}




int main() {
    vector <vector<int>> ip =  { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} };
    cout << method2(ip) << endl;  
   

    return 0;
}
