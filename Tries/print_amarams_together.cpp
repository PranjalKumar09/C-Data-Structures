#include <bits/stdc++.h>
using namespace std;

/* 
PRINT AMAGRAMS TOGETHER
=======================


I/P : "cat", "dog", "tac", "god", "act"
O/P : "cat", "tac",, "act" "dog", "god"
    
    Method 1: Sort them & store
    
    Method 2: Inset all in tree then print from root to termianal (not recommended)

 */


void solve1(vector<string>& words) {
    vector<pair<string , string>> words_pair;

    for (auto& word : words){
        string new_word = word;
        sort(new_word.begin(), new_word.end());
        words_pair.push_back(make_pair(new_word, word));}

    sort(words_pair.begin(), words_pair.end());

    for (auto& word : words_pair)
        cout << word.second <<  " ";
    
}




int main() {
  vector<string> words = {"cat", "dog", "tac", "god", "act"};
  solve1(words);
    return 0;
}

