#include <bits/stdc++.h>
using namespace std;
 
 
#define ll long long
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int last  = -1, ans = -1, c = 0;

    while(n--){
        int t; cin >> t;
        if (last > t) {last=-1; 
            ans = max(c, ans);
            c = 1;
        }
        else c++;

        last = t;
    }
    ans = max(c, ans);
    cout << ans;

}
