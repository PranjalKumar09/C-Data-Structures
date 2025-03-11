#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

/* 
    MAX RECTANGLE IN BINARY MATRIX

    ____________________
    | X | 0 | 1 | 2 | 3 |   by largest area in Histogram 
    |-------------------|
    | X | 0 | 1 | 1 | 0 |   0 ->     1  1  
    | X | 1 | 1 | 1 | 1 |   1 ->  1  2  2  1
    | X | 1 | 1 | 1 | 1 |   2 ->  2  3  3  2
    | X | 1 | 1 | 0 | 0 |   3 ->  3  4  0  0
    ---------------------

    we have to add the element of top current area compute , and if zero zome dont add

 */


void print_array(vector<int> &arr){
    for (int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void prev_smallest_element(vector<int> &ip){
    stack<int> st;
    st.push(-1);
    vector<int> ans(ip.size(), -1); 
    for (int i = 0; i < ip.size(); i++){
        int curr = i;
        while (!st.empty() && st.top() != -1 && ip[st.top()] >= ip[curr]) 
            st.pop();
        if (!st.empty()&& st.top() != -1)
            ans[i] = st.top();
        st.push(curr);
    }
    ip = ans;
}
void next_smallest_element(vector<int> &ip){
    stack<int> st;
    st.push(-1);
    vector<int> ans(ip.size(), -1); 
    for (int i = ip.size()-1; i >= 0; i--){
        int curr = i;
        while (!st.empty() && st.top() != -1 && ip[st.top()] >= ip[curr]) 
            st.pop();
        if (!st.empty()&& st.top() != -1 )
            ans[i] = st.top();
        st.push(curr);
    }
    ip = ans;
}

int largest_rectangular_area(vector<int> &ip){
    int n  = ip.size() , area = 0;

   vector<int> next(ip.begin(), ip.end());  // Copying values of ip to next
    vector<int> prev(ip.begin(), ip.end());  // Copying values of ip to prev
        next_smallest_element(next);
    prev_smallest_element(prev);
    // print_array(next);
    // print_array(prev);

    for (int i = 0; i < n; i++){
        int l = ip[i];
        int r = (next[i] == -1) ? n : next[i];
        int b = r - prev[i] - 1; // Corrected width calculation
        area = max(area , b * l);
    }
    return area;
}

int solve(vector<vector <int>> & matrix){
    int area = largest_rectangular_area(matrix[0]);
    for (int i = 1; i < matrix.size(); i++){
        for (int j = 0 ; j < matrix.size(); j++){
            if (matrix[i][j])
                matrix[i][j] += matrix[i-1][j];
            area = max (area ,largest_rectangular_area(matrix[1]) );
        }
    }
    return area;    
}


int main() {
    vector< vector<int>> ip = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    cout << solve(ip) << endl;
    
  
    

    return 0;
}
