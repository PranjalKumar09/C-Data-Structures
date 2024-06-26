#include <bits/stdc++.h>
using namespace std;

long long check(long long mid, int n) {
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        if (result > LLONG_MAX / mid) // Avoid overflow
            return LLONG_MAX;
        result *= mid;
    }
    return result;
}

int find_nth_root(int num, int n) {
    if (num < 0 || n <= 0) // Input validation
        return -1;
    if (num == 0) // The nth root of 0 is 0 for any n > 0
        return 0;

    long long low = 1, high = num;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long result = check(mid, n); // Calculate once
        if (result == num)
            return mid;
        else if (result < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // If nth root doesn't exist
}

int main() {
    int num = 81, n = 4;
    int root = find_nth_root(num, n);
    if (root != -1)
        cout << "The " << n << "th root of " << num << " is " << root << endl;
    else
        cout << "The " << n << "th root of " << num << " does not exist" << endl;
    return 0;
}
