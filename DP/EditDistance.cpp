#include <bits/stdc++.h>
using namespace std;

/*

    MINIMUM OPERATION TO CONVERT S1 TO S2

        Operation
            1. Insert   -> i  , j-1
            2. Remove   -> i-1, j
            3. Replace  -> i-1, j-1

        Max operation -> l1 + l2;

        l1


 */
string s1 = "horse";
string s2 = "ros";

int l1 = s1.length(), l2 = s2.length();

int f1(int i, int j)
{
    if (i == -1)
        return j + 1; // Case 1: if s1 is empty, we need to insert j+1 characters from s2 to make them equal.
    if (j == -1)
        return i + 1; // Case 2: if s2 is empty, we need to delete i+1 characters from s1 to make them equal.

    if (s1[i] == s2[j])
        return f1(i - 1, j - 1); // Case 3: if characters match, no operation needed, just move to the next character in both strings.

    return 1 + min({f1(i - 1, j), f1(i, j - 1), f1(i - 1, j - 1)});
}
int f2(int i, int j, vector<vector<int>> &dp)
{
    if (i == -1)
        return j + 1;
    if (j == -1)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = f2(i - 1, j - 1, dp);

    return dp[i][j] = 1 + min({f2(i - 1, j, dp), f2(i, j - 1, dp), f2(i - 1, j - 1, dp)});
}

int f3()
{
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; i++)
        dp[i][0] = i;
    for (int i = 0; i <= l2; i++)
        dp[0][i] = i;

    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; //
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }

    return dp[l1][l2];
}

int f4()
{
    vector<int> dp(l2 + 1, 0), prev(l1 + 1);

    for (int i = 0; i <= l2; i++)
        prev[i] = i;

    for (int i = 1; i <= l1; i++){
        dp[0] = i;
        for (int j = i; j <= l2; j++){
            if (s1[i - 1] == s2[j - 1])
                dp[j] = dp[j - 1]; //
            else
                dp[j] = 1 + min({prev[j], dp[j - 1], prev[j - 1]});
        }
        prev = dp;
    }
    return dp[l2];
}

int main()
{
    cout << f1(l1 - 1, l2 - 1) << endl;

    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    cout << f2(l1 - 1, l2 - 1, dp) << endl;

    cout << f3() << endl;
    cout << f4() << endl;

    return 0;
}