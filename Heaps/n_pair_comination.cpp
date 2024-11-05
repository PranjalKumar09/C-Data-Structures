#include <bits/stdc++.h>
using namespace std;

/*  
N max pair combintion
===================== 
    A => 1 - 2 - 3 - 4
    B => 2 - 7 - 6 - 9

    (Both array of same size)

    latest pair -> 4 & 9 , 3 & 9 , 4 & 6, ----

    maxHeap <int    , int   ,   int>
            sum     , A(idx), B(idx)
    
    o/p : vector<int> ans(N);

    TC = O(N log N)
    SC = O(N)
*/

vector<int> solve(vector<int> &A, vector<int> &B, int N) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>> pq; // max-heap
    set<pair<int, int>> s; // store used indices

    int size = A.size();
    pq.push({A[size - 1] + B[size - 1], {size - 1, size - 1}});
    s.insert({size - 1, size - 1});
    
    vector<int> ans;
    
    while (N-- > 0) {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        int L = top.second.first, R = top.second.second;

        if (L > 0 && s.find({L - 1, R}) == s.end()) {
            pq.push({A[L - 1] + B[R], {L - 1, R}});
            s.insert({L - 1, R});
        }
        
        if (R > 0 && s.find({L, R - 1}) == s.end()) {
            pq.push({A[L] + B[R - 1], {L, R - 1}});
            s.insert({L, R - 1});
        }
    }

    return ans;
}

int main() {
    vector<int> A = {1, 4, 2, 5};
    vector<int> B = {3, 6, 1, 2};
    int N = 3;

    vector<int> result = solve(A, B, N);

    cout << "Top " << N << " maximum sums are: ";
    for (int sum : result) 
        cout << sum << " ";
    
    cout << endl;

    return 0;
}

