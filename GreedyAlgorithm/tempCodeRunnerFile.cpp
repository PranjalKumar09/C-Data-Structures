#include <bits/stdc++.h>
using namespace std;


/* 
    Jump Game2

    it is guaranteed that you will reach end, tell minimum  no of steps 


    There is dp solution too buts its complexity more
    Greedy solution here is better
    TC = O(N)
    SC = O(1)
    
 */

vector<int> arr = {2, 3, 1, 0, 4};


int solve(){
    int n = arr.size();

    int l = 0 , r = 0;
    int jumps = 0;
    
    while (r < n-1){
        int maxJump = 0;
        for (int i = l; i <= r; i++){
            maxJump = max(maxJump, arr[i] + i);
        }
        l = r + 1;
        r = maxJump;
        jumps++;
    }

}
int main() {
    
    cout << solve() << endl;    
    return 0;
}
