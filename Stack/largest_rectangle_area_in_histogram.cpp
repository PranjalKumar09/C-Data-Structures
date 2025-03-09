#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

/* 
     LARGEST RECTANGLE AREA IN HISTOGRAM
    
      I/P => {3, 5, 1, 7, 5, 9}

                            *                       
                            *                               
                    *       *                           
                    *       *                                            
            *       *   *   *                                           
            *       *   *   *                                
        *   *       *   *   *                             
        *   *       *   *   *                            
        *   *   *   *   *   *  
        ======================
        3   5   1   7   5   9 
        ======================
        0   1   2   3   4   5 

            i
                    j
            width = j - 1 + 1






 */

int method1(vector<int> &ip){
    int maxi_area= 0;
    for (int i = 0; i<ip.size(); i++){
        int minHight = INT_MAX;
        for (int j = i; j<ip.size(); j++){
            minHight  = min(minHight , ip[j]);
            maxi_area = max(maxi_area, (j - i + 1) * minHight);
            // cout << "i->" << i << "  j->" << j << "  maxi_area " << maxi_area << "  minHight " << minHight << endl;
        }   }
    return maxi_area;
}



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

int method2(vector<int> &ip){
    int n  = ip.size() , area = 0;

   vector<int> next(ip.begin(), ip.end());  // Copying values of ip to next
    vector<int> prev(ip.begin(), ip.end());  // Copying values of ip to prev
        next_smallest_element(next);
    prev_smallest_element(prev);
    print_array(next);
    print_array(prev);

    for (int i = 0; i < n; i++){
        int l = ip[i];
        int r = (next[i] == -1) ? n : next[i];
        int b = r - prev[i] - 1; // Corrected width calculation
        area = max(area , b * l);
    }
    return area;
}



int main() {
    vector <int> ip = {2,1,5,6,2,3,1};
    cout << method1(ip) << endl;
    cout << method2(ip) << endl;
  
    

    return 0;
}
