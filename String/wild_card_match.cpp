/* 


Wild card algorithm : DP , Tabulation  , Memorization 



we are checking from back  * can be element or not be => i1 - 1 or i2 - 1



 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;




bool isAllstars(string &str, int i ){
    for(int j=0;j<=i;j++)
        if(str[i] != '*')return false;    
    return true;
}

bool wildcard_method1(string &str1 , string &str2 , int i1 , int i2 , vector<vector<bool> > &dp){
    if (i1 < 0 && i2 < 0)return true;
    if (i1 < 0 )return false;
    if (i2 < 0 )return isAllstars(str1,i1);
    if (dp[i1][i2]  != 0) return dp[i1][i2];
    if (str1[i1] == '?' || str1[i1] == str2[i2]) return dp[i1][i2] = wildcard_method1(str1 , str2, i1-1, i2-1 , dp);
    if (str1[i1] == '*') return dp[i1][i2] = wildcard_method1(str1 , str2, i1, i2-1 , dp) || wildcard_method1(str1 , str2, i1-1, i2 , dp);
    return false;
}


bool method1(string &str1, string &str2){
    vector<vector<bool> > v1 (str1.size(), vector<bool>(str2.size(), 0));
    return wildcard_method1(str1,str2,str1.size()-1,str2.size()-1,v1);

}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";
    cout << endl;
    if (method1(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";
    cout << endl;
    return 0;
}