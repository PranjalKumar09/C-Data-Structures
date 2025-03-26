#include <bits/stdc++.h>
using namespace std;


/* 
    Jump Game


    catch here is 0 , if there is zero then there is chance of False

    we have to check , was current index reachable
 */

vector<int> arr = {2, 3, 1, 0, 4};


bool solve(){
    int n = arr.size();

    int maxReachable = 0;
    
    for (int i  = 0; i < n; i++){
        if (i > maxReachable) return false;
        maxReachable = max(maxReachable, i + arr[i]);
    }

}
int main() {
    
    cout << solve() << endl;    
    return 0;
}
