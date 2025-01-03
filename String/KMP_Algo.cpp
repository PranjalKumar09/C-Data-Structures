#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to search for pattern in the text using KMP algorithm

// Function to build the longest prefix-suffix (LPS) array
vector<int> buildLPS(string &pat)
{
    int m = pat.size();
    vector<int> lps(m, 0); // LPS array initialized with 0s
    int len = 0;           // Length of the previous longest prefix suffix
    int i = 1;             // We start from the second character of the pattern

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                // This is tricky. Consider the example "AAACAAAA" and i = 7.
                len = lps[len - 1]; // Try to find a shorter prefix
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function to search for pattern in the text using KMP algorithm
vector<int> search(string &pat, string &txt)
{
    vector<int> ans;
    vector<int> lps = buildLPS(pat); // Get the LPS array
    int n = txt.size(), m = pat.size();

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]

    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            ans.push_back(i - j); // Pattern found, add the index
            j = lps[j - 1];       // Use the LPS to avoid unnecessary re-evaluations
        }
        else if (i < n && pat[j] != txt[i])
        {
            // Mismatch after j matches
            if (j != 0)
            {
                j = lps[j - 1]; // Use the LPS to skip characters
            }
            else
            {
                i++;
            }
        }
    }

    return ans;
}

int main()
{
    string txt = "ababcababcabc";
    string pat = "abc";
    vector<int> result = search(pat, txt);

    for (int idx : result)
    {
        cout << idx << " ";
    }

    return 0;
}
