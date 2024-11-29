#include <bits/stdc++.h>
using namespace std;

/* 
SUM OF MINIMU MAXIMUM ELEMENT OF SIZE K

TC = O(N)


 */

int solve(int k , vector<int> &arr){
    queue<int> maxi , mini;
    for (int i = 0 ; i < k ; i++){
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        mini.pop();
        maxi.push(i);
        mini.push(i);
    }
    int ans = arr[maxi.front()] + arr[mini.front()];
    for (int i = k ; i < arr.size() ; i++){
        while (!maxi.empty() && (arr[maxi.back()] <= arr[i] || i-maxi.front()>=k))
        maxi.pop();
        maxi.push(i);
        while (!mini.empty() && (arr[mini.back()] >= arr[i] || i-mini.front()>=k))
        mini.pop();
        mini.push(i);
        ans = max(ans, arr[maxi.front()] + arr[mini.front()]);
    }
    return ans;
}

  

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int result = solve(k, arr);
    cout << result << endl;
    return 0;
}