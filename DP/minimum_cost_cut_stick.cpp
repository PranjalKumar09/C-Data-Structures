
#include <bits/stdc++.h>
using namespace std;

vector<int> cuts = {3, 5, 1, 4};
int n = 7; // Stick length


int f(int i, int j) {
    if (i > j) return 0;

    int min_val = INT_MAX;

    // Try all partitions between i and j
    for (int k = i; k <= j; k++) {
        int cost = f(i, k-1 ) + f(k + 1, j) + cuts[j+1 ] - cuts[i - 1];
        min_val = min(min_val, cost);
    }

    return min_val;
    
}



int f1(int i, int j, vector<vector<int> > & dp) {
    if (i > j) return 0;
    if (dp[i-1][j]!= -1) return dp[i-1][j];

    int min_val = INT_MAX;

    // Try all partitions between i and j
    for (int k = i; k <= j; k++) {
        int cost = f1(i, k-1,dp ) + f1(k + 1, j,dp) + cuts[j+1 ] - cuts[i - 1];
        min_val = min(min_val, cost);
    }

    return dp[i-1][j] = min_val;
    
}

int f2(){

    // cout << cuts[0] << endl;

    int c = cuts.size() - 2; // Number of original cuts
    vector<vector<int> > dp(c+2, vector<int>(c+2,0));

    for (int i = c; i >= 1; i--){
        for (int j = i; j <= c; j++){
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++){
                int cost = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i - 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }



    return dp[1][c];
}





int main() {
    
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int c = cuts.size() - 2; // Number of original cuts
    cout << endl <<  f(1, c) << endl; // Compute minimum cost from 1 to c cuts

    vector<vector<int>> dp(c+1, vector<int>(c+1,-1));

    cout << endl <<  f1(1, c, dp) << endl; // Compute minimum cost from 1 to c cuts

    cout << endl <<  f2() << endl; // Compute minimum cost from 1 to c cuts

    // cout << endl <<  f3() << endl; // Compute minimum cost from 1 to c cuts




    return 0;
}




/* 
    MINIMUM COST TO CUT STICKS

A stick of length n.

An array cuts[] representing the positions along the stick where you’re allowed to cut.

cost is equal to the current length of the stick being cut


    array is sorted
*/
