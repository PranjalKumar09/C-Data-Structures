#include <bits/stdc++.h>
using namespace std;


vector<int> arr;
int k, n;

/* 
    COUNT PARTITIONS WITH GIVEN DIFFERENCE


    S1 - S2 = k
    (S1 = total - S2)

    total - S2 - S2 = k
    total - 2*S2 = k
    S2 = (total - k) / 2

    now it should be
        total - k >= 0
        total - k should be even


 */




int fn5() {
    vector<int> dp(k+1, 0);
    dp[0] = 1;  // Base case

    for (int i = 0; i < n; i++) 
        for (int j = k; j >= arr[i]; j--)   
            dp[j] = dp[j] + dp[j - arr[i]];
        
    

    return dp[k];
}

void countPartitions(){

    int total = accumulate(arr.begin(), arr.end(), 0);

    if (total < k || (total - k) % 2 != 0){
        cout << 0 << endl;
        return;
    }
    k = (total - k) / 2;

    cout << fn5() << endl;
}

int main() {

    arr = {5,2,6,4};
    n = arr.size(), k =3;
    
    countPartitions();
}
