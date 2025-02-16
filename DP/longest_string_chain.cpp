#include <bits/stdc++.h>
using namespace std;

/*
    LONGEST STRING CHAIN


    we can do with longest increasing subseqence

    if difference bw  -> one


    so compare with is it reaching end properly
*/

vector<string> words = {"a","b","ba","bca","bda","bdca"};
int n = words.size();

bool compare(string &s1, string &s2){
    if (s1.size() != s2.size()+1) return false;

    int first = 0, second = 0;
    while (first < s1.size()) {
        if (s1[first] == s2[second]){
        first++;
        second++;}
        else first++;
    }
    return first == s1.size() && second==s2.size();
}


bool comparator(string &s1, string &s2) {
    return s1.size() < s2.size();
}


vector<string> longestStringChain() {
    

    sort(words.begin(), words.end(), comparator);

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);

    for (int i = 0; i < n; i++) {
        hash[i] = i;
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (compare(words[i], words[prev_index]) && 1 + dp[prev_index] > dp[i]) {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<string> temp;
    temp.push_back(words[lastIndex]);

    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(words[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}



int main(){
    cout << endl;
    vector<string> result = longestStringChain();
    // longestStringChain();
    for (auto &str : result)
        cout << str << " ";
    cout << endl;


    return 0;
}