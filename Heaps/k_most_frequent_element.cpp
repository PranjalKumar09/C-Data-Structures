#include <bits/stdc++.h>
using namespace std;

/*  
K most Frequent Elements 
========================
    arr[] = {3, 1, 4, 4, 5, 2, 6, 1}, K = 2
    Output: 4 1

    Method 1: B.F. by Hash Map <element, Frequency>
        then sorting on basis of frequency
        TC: O(N log N) + O(N)
            sorting       hashing

    Method 2: Max Heap -> pop top k elements
        TC: O(N + N + K log N) = O(K log N)

    
*/
class Node {
    public:
    int no, freq;
    Node(int no, int freq) {this->no = no; this->freq = freq;}
};
class compare{
    public:
    bool operator()(Node a, Node b){
        return a.freq > b.freq;
    }
};
vector<int> solve(vector<int> &arr, int k) {
    unordered_map<int, int> mp;
    for (int num : arr) {
        mp[num]++;
    }
    
    priority_queue<Node, vector<Node>,compare> pq;
    
    // Populate the priority queue with the top k elements by frequency
    for (auto it : mp) {
        pq.push(Node(it.first, it.second));
        if (pq.size() > k) {
            pq.pop(); // Remove the element with the smallest frequency
        }
    }
    
    // Extract the top k frequent elements from the priority queue
    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().no);
        pq.pop();
    }
    
    // Reverse the order to return the elements in descending order of frequency
    reverse(ans.begin(), ans.end());
    
    return ans;
}




int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 4;

    vector<int> result = solve(arr, k);

    cout << "The " << k << " most frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

