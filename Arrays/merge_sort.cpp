#include <iostream>
#include <vector>

using namespace std;
/* 
    Merge Sort
    ==========
    
 */
void merge(vector<int>& arr, int low, int high, int mid) {
    int left = low, right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++) arr[i] = temp[i - low];
}



void mergesort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, high, mid);
}

void mergeArrays(vector<int> &a, vector<int> &b)
{

    /*
    This is very Hard level algo, in this we merge without using extra space
    */
    int n = a.size(), m = b.size();
    int gap = ceil((n + m) / 2.0);

    while (gap > 0)
    {
        int i = 0, j = gap;

        // Compare elements in the combined array view
        while (j < (n + m))
        {
            int val1 = (i < n) ? a[i] : b[i - n];
            int val2 = (j < n) ? a[j] : b[j - n];

            // Swap if out of order
            if (val1 > val2)
            {
                if (i < n && j < n)
                {
                    swap(a[i], a[j]); // Both in `a[]`
                }
                else if (i < n)
                {
                    swap(a[i], b[j - n]); // `a[]` and `b[]`
                }
                else
                {
                    swap(b[i - n], b[j - n]); // Both in `b[]`
                }
            }
            i++;
            j++;
        }

        // Reduce the gap
        gap = (gap == 1) ? 0 : ceil(gap / 2.0);
    }
}

void display(const vector<int>& arr) {
    for (int num : arr) 
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    display(arr);

    int n = arr.size();
    mergesort(arr, 0, n - 1);

    cout << "Sorted array: ";
    display(arr);

    return 0;
}

/* 

Store 1 gb of data with only 100 mb storing techniquee merge sort
merge sort has lowest wrost case complexity 


Application for merge sort

* Storing large datasets  wrost time dependency = 0 (nlog n) so well to large data 
* External storing 
* Custom storing
* Inversion count problem


Merge sort 

Advantage 
Stablity
Guranted worst case Performance
Parallizable (easilhy parallezied to take advantage of multiple processor or thread)

Disadvantage
Space Complexity
Not always optimal 
For small data sets
(not inplace requie additional memory )





 */


