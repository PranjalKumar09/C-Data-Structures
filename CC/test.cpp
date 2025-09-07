#include <bits/stdc++.h>
using namespace std;
 
void solveSudoku(vector<vector<char>>& board) {
    vector<vector<char>> st1(9, vector<char>(9)), st2(9,vector<char>(9)), st3(9,vector<char>(9));

    


}
#define ll long long
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    vector<int> v;

    for (int i = 1; i <= n; i++){
        int a1; cin >> a1;
        int temp = (a1+m-1)/m;

        if (temp > maxi ){
            v.clear();
            v.push_back({i, a1});
            maxi = temp;
        }
        else if (temp == maxi) v.push_back({i, a1});
    }

    for (int i = 0; i < n/3;)

    cout << v[v.size() - 1].first;

}



