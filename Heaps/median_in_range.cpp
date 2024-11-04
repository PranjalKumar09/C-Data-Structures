#include <bits/stdc++.h>
using namespace std;

/* 
Median in a stream
==================                
Median  in flow coming    2 ,[3] , 4
(not sorted)

    Method 1: Sort Array
        It is running stream so does'nt change in new element in new element
        By Insertion Sort : 
        TC = O(n^2)

    Method 2: O.S.
        TC = O(n log n)

        { ----    M    ----   }
        left           right
        element < M  < right

                      case 0                 case 1 
        odd size  : left   right    or     left   right  
                    n-1      n              n      n-1   
                (minheap)                         (median)
                (median)                          (maxheap)

        even size: case 3     
                left    right
                n        n
                top of max , min heap  

        TC = O(n log n)  

    if       
*/        

int signum(int a , int b){
    if(a > b) return 1;
    if(a < b) return -1;
    return 0;
}
void callMedian(int element, priority_queue<int, vector<int>, greater<int>> &minHeap, priority_queue<int> &maxHeap, int &median){
    switch (signum(maxHeap.size(), minHeap.size())){
        case 0: 
            if (element > median){
                minHeap.push(element);
                median = minHeap.top();
            }
            else{
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;
        case 1: 
            if (element > median)
                minHeap.push(element);            
            else{
                minHeap.push(maxHeap.top());            
                maxHeap.pop();
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top())/2;
            break;
        case -1:
            if (element > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);}            
            else
                maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
            break;
    }
}

vector<int> solve(vector<int> &arr){
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int median = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        callMedian(arr[i], minHeap, maxHeap, median) ;
        ans.push_back(median);
    }
    return ans;
}

void print_arr(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    
    cout << endl;
}

int main() {
    vector<int> arr ={5, 15, 1, 3 };
    print_arr(arr);
    vector<int> ans = solve(arr);
    print_arr(ans);

    return 0;
}