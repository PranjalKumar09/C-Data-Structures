#include <bits/stdc++.h>
using namespace std;

/* 
Merge k sorted array
====================
    Method 1: B.F.
        TC = O(n*k log n*k)
        SC = O(n*k)

    Method 2: by min Heap
        TC = O(n*k log k)
        SC = O(k)
*/

vector<int> solve1(vector<vector<int>> &arr){
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) 
        for (int j = 0; j < arr[i].size(); j++) 
            ans.push_back(arr[i][j]);
    sort(ans.begin(), ans.end());
    return ans;
}


class Node{
public:
    int data;
    int i; // index of array from which element taken
    int j; // next index of array from which index to be picked
    Node(int data, int row, int  col){
        this->data = data;
        this->i = row;
        this->j = col;
    }   
};
class  compare{
public: 
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};

vector<int> solve2(vector<vector<int>> &arr) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    vector<int> ans;
    
    // Pushing first element of every array into the heap
    for (int i = 0; i < arr.size(); i++) {
        if (!arr[i].empty()) {
            Node* node = new Node(arr[i][0], i, 1);
            minHeap.push(node);
        }
    }

    // Extracting elements from heap and adding new elements
    while (!minHeap.empty()) {
        Node* node = minHeap.top();
        minHeap.pop();
        ans.push_back(node->data);
        int i = node->i;
        int j = node->j;
        if (j < arr[i].size()) {
            Node* newNode = new Node(arr[i][j], i, j + 1);
            minHeap.push(newNode);
        }
        delete node; // Free memory
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 5, 8},
        {2, 3, 7},
        {4, 6, 9}
    };

    vector<int> result1 = solve1(arr);
    vector<int> result2 = solve2(arr);

    cout << "Result from solve1 (simple sort): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result from solve2 (min-heap merge): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}