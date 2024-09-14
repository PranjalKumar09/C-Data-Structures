#include <bits/stdc++.h>
using namespace std;

/*
ASRTEROID COLLISIONS 

    +ve : right 
    -ve : left

    ip = [5,10,-5]
    op = [5,10]

    ip = [-1,3,2,-3]
          <- --> <-
            2 vs -3 => -3
            -3 vs 3 => 0

    op =  [-1]  

    we will push in stacks as we will get we will pop previous 

    we will include starting one element in stak

*/


vector<int> solve(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    for (int i  = 0 ; i < n; i++){
        if (arr[i]>0 || st.empty()) st.push(arr[i]); // if positive
        else { // if negative
            while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i]) ) st.pop(); // means negative side powerful
            if (!st.empty() && st.top() == abs(arr[i]) ) st.pop();  // handle both x = x and x = -x
            else if ( st.empty() || st.top() < 0) 
                st.push(arr[i]);  // means postive side powerful

        }
        
    }   
    
    // now return arr by iterating stack
    vector <int> answer;
    while (!st.empty()){
        answer.push_back(st.top());
        st.pop();

    }

    return answer;
}

int main() {
    // Test case 1
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = solve(asteroids1);
    cout << "Test case 1 result: ";
    for (int a : result1) {
        cout << a << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = solve(asteroids2);
    cout << "Test case 2 result: ";
    for (int a : result2) {
        cout << a << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = solve(asteroids3);
    cout << "Test case 3 result: ";
    for (int a : result3) {
        cout << a << " ";
    }
    cout << endl;

    // Test case 4
    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> result4 = solve(asteroids4);
    cout << "Test case 4 result: ";
    for (int a : result4) {
        cout << a << " ";
    }
    cout << endl;

    

} 