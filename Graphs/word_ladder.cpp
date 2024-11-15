#include <bits/stdc++.h>
using namespace std;

/*
    Word Ladder
    -----------
    beginword = "lit" endword = "cog"
    Word list = [hot, dot , dog, lot, log, cog ]

    hit -> hot -> dot -> dog -> cog (minimum change)

    ait         hia
    bit   hit   hib
    -           -
    zit         hiz

    o/p -> minimum no of changes

    TC : O(n*m*26)
    SC : O(n)
*/

int solve(string start, vector<string> & wordList, string target) {
    queue<pair<string, int>> q; // BFS , <word , steps>
    q.push({start, 1});

    unordered_set<string> st(wordList.begin(), wordList.end()); // to store elements & carry out search in delete in O(1)
    st.erase(start);

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop(); // it has minimum steps , & visited

        if (word == target) return steps;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (st.find(word) != st.end()) {
                    q.push({word, steps + 1});
                    st.erase(word);
                }

                word[i] = original; // backtrack
            }
        }
    }
    return 0; // no transformation possible
}
int main() {
    // Hardcoded values for testing
    string start = "hit";
    string target = "cog";
    
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    // Call solve function and print the result
    int result = solve(start, wordList, target);
    
    if (result == 0)
        cout << "No transformation possible." << endl;
    else
        cout << "Minimum transformations: " << result << endl;


    return 0;
}
