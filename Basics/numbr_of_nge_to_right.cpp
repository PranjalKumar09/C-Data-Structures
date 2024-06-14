#include <bits/stdc++.h>
using namespace std;

/*
NUMBER OF NGEs TO RIGHT
NGEs = Next Greater Elements
 */

int ans(vector<int> &ip, int element){
    int count = 0;
    bool check = false;
    vector<int> result(ip.size() , 0);
    for (int i = 0; i < ip.size(); i++){
        if (ip[i] == element)
            check = true;
        if (check && ip[i] > element)
            count++;        
    }
    return count;

}
vector<int> solve(vector<int>& arr , vector<int> &ip){
    vector<int> result(ip.size() , 0);
    for (int i = 0; i < ip.size(); i++)
        result[i] = ans(arr, ip[i]);        
    return result;
    
}


int main() {
    // Input section
    int n, m;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of queries: ";
    cin >> m;
    vector<int> ip(m);
    cout << "Enter query elements: ";
    for (int i = 0; i < m; i++) {
        cin >> ip[i];
    }

    // Solve the problem
    vector<int> result = solve(arr, ip);

    // Output the results
    cout << "Results: ";
    for (int i = 0; i < m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
