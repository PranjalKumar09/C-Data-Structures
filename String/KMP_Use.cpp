#include <bits/stdc++.h>
using namespace std;

int minChar(string &s)
{
    // Create the temporary string for LPS computation
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    string temp = s + '#' + reversed_s;

    // Compute the LPS array
    int n = temp.size();
    vector<int> lps(n, 0);

    for (int i = 1; i < n; i++)
    {
        int len = lps[i - 1];
        while (len > 0 && temp[i] != temp[len])
        {
            len = lps[len - 1];
        }
        if (temp[i] == temp[len])
        {
            len++;
        }
        lps[i] = len;
    }

    // Result is the difference between the string length and the longest palindromic prefix
    return s.size() - lps[n - 1];
}

int main()
{
    string s = "abc";
    cout << minChar(s) << endl; // Output: 2

    s = "aacecaaaa";
    cout << minChar(s) << endl; // Output: 2

    return 0;
}
