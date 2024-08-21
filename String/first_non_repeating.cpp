#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* 
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'

 */


string first_non_repeating(string A) {
    vector<int> vis(26, 0); // record frequency
    string ans = "";
    int n = A.length();

    for (int i = 0; i < n; i++) {
        vis[A[i] - 'a']++;

        char first_non_repeating = '#'; // Initialize with '#' as default

        for (int j = 0; j <= i; j++) { // Iterate up to the current character
            if (vis[A[j] - 'a'] == 1) {
                first_non_repeating = A[j]; // Update the first non-repeating character
                break;
            }
        }

        ans.push_back(first_non_repeating); // Append the first non-repeating character to ans
    }

    return ans;
}

int main() {
    // Input string
    string input_string;
    cout << "Enter a string: ";
    cin >> input_string;

    // Find the first non-repeating character for each prefix
    string result = first_non_repeating(input_string);

    cout << "Result: " << result << endl;
    return 0;
}
