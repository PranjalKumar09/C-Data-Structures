#include <bits/stdc++.h>
using namespace std;

/* 
Smallest Range in K list
========================                
    
    smallest range in which every list element

    Method 1: Comparing with each element
        TC = O(n^2 + k^2)        SC = O(n)

    Method 2: You can't decrease max because lift is sorted & first one is minimum 
        now find -> (min(arr) , max(arr))   -> so we gotten one list now
    
        now check by increasing minimum each list
           ___ -> stored
        { | 1 | , 10, 11}        [1 -> 5] (lowest) ->  [1-10]
        { | 2 | ,  3, 20}        [2 -> 10] -> [3 -> 10] -> [3 -> 20]
        { | 5 | ,  6, 12}        [5 -> 20] 
          -----
        
        if list ene process ene
        
        TC = O(n k^2)        SC = O(k)        
        
    Method 3: by Heaps 
        store starting element in min Heap , max track while doing above , jab koi list khatam ho jai toh ruk jaise , ans start , ans end

        range = ansEnd - ansStart
        TC = O(n k log k)        SC = O(k)        
*/        
int solve2(vector<vector<int>>& arr) {
    int k = arr.size();
    int n = arr[0].size();
    
    vector<int> indices(k, 0); // pointers to track indices in each list
    int mini = INT_MAX, maxi = INT_MIN;
    
    // Initialize pointers and current min/max values
    for (int i = 0; i < k; ++i) {
        mini = min(mini, arr[i][0]);
        maxi = max(maxi, arr[i][0]);
    }
    
    int smallestRangeLength = INT_MAX; // current smallest range length
    
    // Use two pointers technique to find the smallest range length
    while (true) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        int minIdx = -1;
        
        // Find the list with the current minimum value
        for (int i = 0; i < k; ++i) {
            if (indices[i] < n && arr[i][indices[i]] < minVal) {
                minVal = arr[i][indices[i]];
                minIdx = i;
            }
            maxVal = max(maxVal, arr[i][indices[i]]);
        }
        
        // Update the smallest range length if found a smaller one
        if (maxVal - minVal < smallestRangeLength) 
            smallestRangeLength = maxVal - minVal;
        
        
        // Move the index forward for the list with the minimum value
        indices[minIdx]++;
        
        // Break if any list is exhausted
        if (indices[minIdx] == n)
            break;
    }
    
    return smallestRangeLength + 1; // return the length of the smallest range
}



class Node{
public:
    int data, row, col;
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


int solve3(vector<vector<int> > &arr){
    int k = arr.size();
    int n = arr[0].size();
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node* , vector<Node*>, compare > minHeap;
    for (int i = 0; i < k ; i++){
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i , 0));
    }
    int start = mini , end = maxi;
    while(!minHeap.empty()){ // process rabges
        Node *temp = minHeap.top(); // minii fetch
        minHeap.pop();
        mini = temp->data;
        if (maxi-mini < end - start){ // range or answer update
            start = mini; // range update
            end = maxi;
        }
        if (temp ->col+1 < n){
            maxi = max(maxi, arr[temp->row][temp->col+1]);
            minHeap.push(new Node(arr[temp->row][temp->col+1], temp->row, temp->col+1)); // it is sorted on the basis of value of array
        }
        else break; // if not next not then get out
    }
    return end - start+1;
}

int main() {
    vector<vector<int>> arr = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    int rangeLength = solve3(arr);

    cout << "Length of the smallest range: " << rangeLength << endl;

    return 0;
}