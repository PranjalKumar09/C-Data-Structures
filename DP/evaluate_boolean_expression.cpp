
#include <bits/stdc++.h>
using namespace std;


/* 
EVALUATE BOOLEAN EXPRESSION 

even index are T , F
odd index are operators &, | , ^

 */

typedef long long ll;

ll f(int i, int j, bool isTrue, string &exp) {
    if (i == j) {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    ll ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        ll lT = f(i, k - 1, true, exp);
        ll lF = f(i, k - 1, false, exp);
        ll rT = f(k + 1, j, true, exp);
        ll rF = f(k + 1, j, false, exp);

        if (exp[k] == '&') {
            if (isTrue)
                ans += lT * rT;
            else
                ans += lF * rF + lT * rF + lF * rT;
        }

        else if (exp[k] == '|') {
            if (isTrue)
                ans += lT * rT + lT * rF + lF * rT;
            else
                ans += lF * rF;
        }

        else if (exp[k] == '^') {
            if (isTrue)
                ans += lT * rF + lF * rT;
            else
                ans += lT * rT + lF * rF;
        }
    }

    return ans;
}

ll f1(int i, int j, bool isTrue, string &exp, vector<vector<ll>> &dp) {
    if (i == j) {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    if (dp[i][j]!= -1) return dp[i][j];

    ll ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        ll lT = f1(i, k - 1, true, exp, dp);
        ll lF = f1(i, k - 1, false, exp, dp);
        ll rT = f1(k + 1, j, true, exp, dp);
        ll rF = f1(k + 1, j, false, exp, dp);

        if (exp[k] == '&') {
            if (isTrue)
                ans += lT * rT;
            else
                ans += lF * rF + lT * rF + lF * rT;
        }

        else if (exp[k] == '|') {
            if (isTrue)
                ans += lT * rT + lT * rF + lF * rT;
            else
                ans += lF * rF;
        }

        else if (exp[k] == '^') {
            if (isTrue)
                ans += lT * rF + lF * rT;
            else
                ans += lT * rT + lF * rF;
        }
    }

    return dp[i][j] = ans;
}


ll f2(string exp, int l) {
    vector<vector<vector<ll>>> dp(l, vector<vector<ll>>(l, vector<ll>(2, 0)));

    // Base case: single character (T or F)
    for (int i = 0; i < l; i++) {
        dp[i][i][1] = (exp[i] == 'T');  // Ways to make 'T'
        dp[i][i][0] = (exp[i] == 'F');  // Ways to make 'F'
    }

    for (int len = 3; len <= l; len += 2) { // Only odd lengths (exprs like "T|F")
        for (int i = 0; i <= l - len; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k += 2) {
                ll lT = dp[i][k - 1][1];
                ll lF = dp[i][k - 1][0];
                ll rT = dp[k + 1][j][1];
                ll rF = dp[k + 1][j][0];

                if (exp[k] == '&') {
                    dp[i][j][1] += lT * rT;
                    dp[i][j][0] += lF * rF + lT * rF + lF * rT;
                }

                else if (exp[k] == '|') {
                    dp[i][j][1] += lT * rT + lT * rF + lF * rT;
                    dp[i][j][0] += lF * rF;
                }

                else if (exp[k] == '^') {
                    dp[i][j][1] += lT * rF + lF * rT;
                    dp[i][j][0] += lT * rT + lF * rF;
                }
            }
        }
    }

    return dp[0][l - 1][1];
}

int main(){
    string exp = "F|T^F";
    int l = exp.length();
    cout << f(0, l - 1, true, exp) << endl;

    vector<vector<ll> > dp(l, vector<ll>(l, -1));
    cout << f1(0, l - 1, true, exp, dp) << endl;

    


    return 0;
}

Tries 
Test
