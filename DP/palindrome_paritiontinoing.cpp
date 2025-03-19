
#include <bits/stdc++.h>
using namespace std;

/* 
    MINIMUM NO OF PARTITIONS? 
    SUCH THAT IT ALL ARE PARTITIONS

    These type of partition also called Front Partition


 */

bool isPalindrome(int i, int j, string& str){
    while (i < j){
        if (str[i]!= str[j]) return false;
        i++; j--;
    }
    return true;
}
int f(int i , int n , string &str){
    if (i == n) return 0;
    
    int minCost = INT_MAX;
    for (int j = i ;  j < n; j++)
        if (isPalindrome(i, j, str)) {
            int cost = 1 + f(j+1, n, str);    
            minCost = min(minCost, cost);
        }

    return minCost;
}


int f1(int i , int n , string &str ,vector<int > &dp){
    if (i == n) return 0;

    if (dp[i]!= -1) return dp[i];
    
    int minCost = INT_MAX;
    for (int j = i ;  j < n; j++)
        if (isPalindrome(i, j, str)) {
            int cost = 1 + f1(j+1, n, str, dp);    
            minCost = min(minCost, cost);
        }

    return dp[i] = minCost;
}


int f2(int n , string &str ){
    vector<int> dp(n+1, 0);


    for (int  i = n-1; i > -1; i--){
        int minCost = INT_MAX;
        for (int j = i ;  j < n; j++)
            if (isPalindrome(i, j, str)) {
                int cost = 1 + dp[j+1];    
                minCost = min(minCost, cost);
            }
        dp[i] = minCost;
    }
    return dp[0];
}




int main(){

    string str =  "bababcbadcede";
    int l = str.length();

    cout << "Minimum cost: " << f(0, l, str) - 1 << endl;

    vector<int> dp(l, -1);
    cout << "Minimum cost: " << f1(0, l, str, dp) - 1 << endl;

    cout << "Minimum cost: " << f2(l, str) - 1 << endl;

 


    return 0;


}