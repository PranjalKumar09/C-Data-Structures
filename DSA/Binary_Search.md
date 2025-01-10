 
 
 ``` cpp
 int kthElement(vector<int>& a, vector<int>& b, int k) {


    
    int m = a.size();
    int n = b.size();
    
    // Ensure `a` is the smaller array
    if (m > n) {
        return kthElement(b, a, k);
    }

    int low = max(0, k - n), high = min(k, m);
    
    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = k - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
        int minRightA = (partitionA == m) ? INT_MAX : a[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
        int minRightB = (partitionB == n) ? INT_MAX : b[partitionB];

        // Check if we found the correct partitions
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            return max(maxLeftA, maxLeftB);
        } else if (maxLeftA > minRightB) {
            high = partitionA - 1; // Move left in `a`
        } else {
            low = partitionA + 1; // Move right in `a`
        }
    }
        return -1;
    }

```
