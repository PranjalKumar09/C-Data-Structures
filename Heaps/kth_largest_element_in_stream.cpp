#include <bits/stdc++.h>
using namespace std;

/*  
K most largest element in Stream 
================================ 

    make Kth largest(int k, vector<int>& arr) -> intiliazes minheap object with integer k & stream of inegers m & streams lf kntegers num

    int add(int val) : appends integer val to stream return element representing kth largest element in stream

    
*/
class Kth_largest{
public:
    priority_queue<int, vector<int> , greater<int> > pq;
    int k;
    Kth_largest(int k, vector<int>& nums) : k(k) {
        for (auto x : nums){
            if (pq.size() < k) pq.push(x);
            else if (pq.size() == k && x >= pq.top()) pq.push(x);
            if (pq.size() > k) pq.pop();
        }
    }
    int add(int val) {
        if (pq.size() < k) 
            pq.push(val);
        else if (val > pq.top()) {
            pq.push(val);
            if (pq.size() > k)  pq.pop();
        }
        return pq.top();}
};


int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    Kth_largest kthLargest(k, nums);

    cout << "Kth largest after adding 3: " << kthLargest.add(3) << endl; // Should print 4
    cout << "Kth largest after adding 5: " << kthLargest.add(5) << endl; // Should print 5
    cout << "Kth largest after adding 10: " << kthLargest.add(10) << endl; // Should print 5
    cout << "Kth largest after adding 9: " << kthLargest.add(9) << endl; // Should print 8
    cout << "Kth largest after adding 4: " << kthLargest.add(4) << endl; // Should print 8

    return 0;
}


