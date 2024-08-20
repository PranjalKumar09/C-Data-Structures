
/* 

Some point about dp approach
size2 is size of both arrays

shifting of index  0 -> 1 , size2 - > size2 + 1

inner loop iterate upto 1 to size2 

so inner all operatiion with indx2 execpt with str1 

 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <typename T>
void displayVector(const std::vector<T>& vec) {
    cout << "[ ";
    for (const auto& element : vec) 
        cout << element << " ";
    
    cout << "]\n";
}


int lcsRecursive(string str1, string str2, int indx1, int indx2) {
    if (indx1 == 0 || indx2 == 0)
        return 0;

    if (str1[indx1 - 1] == str2[indx2 - 1])
        return 1 + lcsRecursive(str1, str2, indx1 - 1, indx2 - 1);
    else
        return max(lcsRecursive(str1, str2, indx1 - 1, indx2), lcsRecursive(str1, str2, indx1, indx2 - 1));
}


int lcsMemoization(string str1, string str2, int indx1, int indx2, vector<vector<int>>& memo) {
    if (indx1 == 0 || indx2 == 0)
        return 0;

    if (memo[indx1][indx2] != -1)
        return memo[indx1][indx2];

    int result;
    if (str1[indx1 - 1] == str2[indx2 - 1])
        result = 1 + lcsMemoization(str1, str2, indx1 - 1, indx2 - 1, memo);
    else
        result = max(lcsMemoization(str1, str2, indx1 - 1, indx2, memo), lcsMemoization(str1, str2, indx1, indx2 - 1, memo));
    memo[indx1][indx2] = result;
    return result;
}




int space_memorization(string str1, string str2) {
    int size1 = str1.length(), size2 = str2.length();
    
    // Initialize vectors with size2 + 1, not size1 + 1 for curr
    vector<int> prev1(size2 + 1, 0), curr(size2 + 1, 0);

    for (int indx1 = 1; indx1 <= size1; indx1++) {
        for (int indx2 = 1; indx2 <= size2; indx2++) {
            if (str1[indx1 - 1] == str2[indx2 - 1])
                curr[indx2] = 1 + prev1[indx2 - 1]; // dp[indx1][indx2] = 1 + dp[indx1-1][indx2-1] 
                // dp[indx1-1] => prev =? 
                // dp[indx1-1][indx2-1]  = prev1[indx2 - 1]
            else
                curr[indx2] = max(prev1[indx2], curr[indx2 - 1]);
                // dp[indx1 ][indx2 ] = max(dp[indx1-1][indx2] , dp[indx1][indx2-1])
                // 
        }
        // Assign curr to prev1 for the next iteration
        prev1 = curr;
    }

    // note if you return prev[size2] then also answer both are same
    return curr[size2];
}





int main() {
    string S1 = "AGGTAB", S2 = "GXTXAYB";
    vector<vector<int>> memory(S1.length() + 1, vector<int>(S2.length() + 1, -1));


    cout << "Length of the lcs is " << lcsRecursive(S1, S2, S1.size(), S2.size()) << endl;

    cout << "Length of the lcs is " << lcsMemoization(S1, S2, S1.size(), S2.size(), memory) << endl;

    cout << "Length of the lcs is " << space_memorization(S1, S2);

    return 0;
}
