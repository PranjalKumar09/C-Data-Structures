#include <bits/stdc++.h>
using namespace std;

/*  
Reorganize String
=================

Rearrange chaacter such that any two adjacent character not same, if not possible return emtpy string
"aab" -> "aba"
"aaab" -> ""
"aabb" -> "abab" or "baba"

    B.F. => Generate n^2 characters & check condition O(n!)



    majority_element > length/2 -> return emtpy

    majority_element< 0 
        count freq with element

    TC = O(N log K)     K -> unique element
    SC = O(N)
        
*/

string solve(string str) {
    unordered_map<char, int> freq_map;
    for (char c : str) 
        freq_map[c]++;
    

    // Max-heap to store characters by frequency
    priority_queue<pair<int, char>> max_heap;
    for (auto& entry : freq_map) 
        max_heap.push({entry.second, entry.first});
    

    string res = "";
    while (max_heap.size() > 1) {
        auto [freq1, char1] = max_heap.top();
        max_heap.pop();
        auto [freq2, char2] = max_heap.top();
        max_heap.pop();

        // Append the two most frequent characters
        res += char1;
        res += char2;

        if (--freq1 > 0) 
            max_heap.push({freq1, char1});
        
        if (--freq2 > 0) 
            max_heap.push({freq2, char2});
        
    }

    // Handle the last character, if any
    if (!max_heap.empty()) {
        auto [freq, ch] = max_heap.top();
        if (freq > 1) 
            return ""; // Return empty string if it's not possible to reorganize
        
        res += ch;
    }

    return res;
}
int main() {
    string str = "aabb";
    cout << solve(str) << endl;

    return 0;
}


