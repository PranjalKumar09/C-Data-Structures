#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

const int INF = INT_MAX;



int printSolution(const vector<int>& solution, int wordCount, const vector<vector<int>>& extraSpaces)  
{  
    int totalCost = 0;
    for (int j = 1; j <= wordCount; ++j) {
        totalCost += extraSpaces[solution[j]][j] * extraSpaces[solution[j]][j];
        cout << "Line number " << j << ": From word no. " << solution[j] << " to " << j << endl;
    }
    totalCost -= extraSpaces[solution[wordCount]][wordCount] * extraSpaces[solution[wordCount]][wordCount]; //reducing last one
    return totalCost;
}  



// inr solve_wap(vector<int< arr , int k ){
//     vector<vector < int > > (arr.size() , vector<int>(arr.size() , -1) ) dp
//     return rec(0 , k , arr , k , dp);
// }
// int rec (int i  , int rem . vector<int> &arr , int &k ,vector<vector < int > > &dp ){
//     if ( i == arr.size() ) return 0;
//     if (dp[i][rem] != -1) return dp[i][rem];
//     int ans = 0;
//     if (arr[i] > rem) ans = (rem + 1) * (rem + 1)  + rec(i+1 , k - arr[i] - 1, dp);
//     else { 
//         int choice1 = (rem + 1) * (rem + 1) + rec(i+1 , k -arr[i] -1, k , dp);
//         int choice1 =  rec(i+1 , rem - arr[i] - 1 , k -arr[i] -1, k , dp);
//     }
//     ans = min(choice1 , choice2);
//     dp[i][rem] = ans;
//     return rec(0,k,arr,k,dp); 
// }   
    
int rec(int i, int rem, const vector<int>& arr, int k, vector<vector<int>>& dp);

int solve_wrap(const vector<int>& arr, int k) {
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1)); // Fixed: Corrected the initialization of dp
    return rec(0, k, arr, k, dp);
}

int rec(int i, int rem, const vector<int>& arr, int k, vector<vector<int>>& dp) {
    if (i == arr.size()) return 0;
    if (dp[i][rem] != -1) return dp[i][rem];

    int ans = 0;
    if (arr[i] > rem) {
        ans = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k, dp); // Fixed: Added arr parameter in the recursive call
    } else {
        int choice1 = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k, dp);
        int choice2 = rec(i + 1, rem - arr[i] - 1, arr, k, dp); // Fixed: Corrected variable name and removed extra parameters
        ans = min(choice1, choice2);
    }
    dp[i][rem] = ans;
    return dp[i][rem]; // Fixed: Changed the recursive call arguments
}
    
    
    
    
// Function to solve the word wrap problem
int solveWordWrap(const vector<int>& wordLengths, int maxWidth)  
{  
    // Calculate extra spaces in a single line. The value extraSpaces[i][j] indicates extra spaces if words from word number i to j are placed in a single line  
    vector<vector<int>> extraSpaces(wordLengths.size() + 1, vector<int>(wordLengths.size() + 1));  

    // lineCost[i][j] will have cost of a line which has words from i to j  
    vector<vector<int>> lineCost(wordLengths.size() + 1, vector<int>(wordLengths.size() + 1));  

    // totalCost[i] will have total cost of optimal arrangement of words from 1 to i  
    vector<int> totalCost(wordLengths.size() + 1);  

    // solution[i] is used to print the solution.  
    vector<int> solution(wordLengths.size() + 1);  

    int i, j;  

    // Calculate extra spaces in a single line. The value extraSpaces[i][j] indicates extra spaces if words from word number i to j are placed in a single line  
    for (i = 1; i <= wordLengths.size(); i++)  
    {  
        extraSpaces[i][i] = maxWidth - wordLengths[i - 1];  
        for (j = i + 1; j <= wordLengths.size(); j++)  
            extraSpaces[i][j] = extraSpaces[i][j - 1] - wordLengths[j - 1] - 1;  // for one more word we will reduce the (word length + 1 (for space)) 
    }  

    // Calculate line cost corresponding to the above calculated extra spaces. The value lineCost[i][j] indicates cost of putting words from word number i to j in a single line  
    for (i = 1; i <= wordLengths.size(); i++)  
    {  
        for (j = i; j <= wordLengths.size(); j++)  
        {  
            if (extraSpaces[i][j] < 0)  
                lineCost[i][j] = INF;  
            else if (j == wordLengths.size() && extraSpaces[i][j] >= 0)  
                lineCost[i][j] = 0;   // we have not to include last one 
            else
                lineCost[i][j] = extraSpaces[i][j] * extraSpaces[i][j];   // now count cost for genral one
        }  
    }  

    // Calculate minimum cost and find minimum cost arrangement. The value totalCost[j] indicates optimized cost to arrange words from word number 1 to j.  
    totalCost[0] = 0;   // starting total cost will 0 
    for (j = 1; j <= wordLengths.size(); j++)  
    {  
        totalCost[j] = INF;  
        for (i = 1; i <= j; i++)  
        {  
            if (totalCost[i - 1] != INF && lineCost[i][j] != INF && (totalCost[i - 1] + lineCost[i][j] < totalCost[j]))  
            {  
                totalCost[j] = totalCost[i - 1] + lineCost[i][j];  // if any minimum total cost then set that one 
                solution[j] = i;  
            }  
        }  
    }  

    // Print the solution  
    int total = printSolution(solution, wordLengths.size(), extraSpaces);  
    return total;
}  

// Function to print the solution recursively

int main() {
    vector<int> wordLengths = {3, 2, 2}; // Example word lengths
    int maxWidth = 4; // Example maximum width

    int totalCost = solveWordWrap(wordLengths, maxWidth);
    cout << "Total cost: " << totalCost << endl;



    cout << endl << endl << "Second Mehtod : " ; 
    cout << solve_wrap(wordLengths, maxWidth);

    cout << endl;
    return 0;
}