#include <bits/stdc++.h>
using namespace std;

/*
    Word Ladder 2
    -------------
    like previous one but here print all shortest sequence in any order it reach target word

    instead or erasing immediately just do it complete level transversal
    
    TC : O(n*m*26)
    SC : O(n)
*/

vector<vector<string>> solve2(string start, vector<string> &wordList, string target)
{
    queue<vector<string>> q;

    q.push({start});
    unordered_set<string> st(wordList.begin(), wordList.end()); // to store words for O(1) access
    st.erase(start);                                            // remove start from the set

    vector<string> usedOnLevel;   // to store words used at the current level
    usedOnLevel.push_back(start); // mark start as used
    int level = 0;                // keep track of BFS levels

    vector<vector<string>> ans; // stores all valid paths

    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        // if the size of the current path increases, it means we've moved to a new level
        if (vec.size() > level)
        {
            level++;
            for (auto &word : usedOnLevel)
                st.erase(word); // remove all used words from the set
            usedOnLevel.clear(); // clear used words for this level
        }

        string lastWord = vec.back(); // the last word in the current path

        // if we reached the target word, add the path to the answer
        if (lastWord == target)
            ans.push_back(vec);
        

        // transform each character of the last word to find next possible words
        for (int i = 0; i < lastWord.size(); i++)
        {
            string temp = lastWord;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                temp[i] = ch; // change one character

                // if the transformed word is in the set
                if (st.find(temp) != st.end())
                {
                    vec.push_back(temp);         // add transformed word to the path
                    q.push(vec);                 // push the new path into the queue
                    usedOnLevel.push_back(temp); // mark it as used for this level
                    vec.pop_back();              // backtrack for the next transformation
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans; // return all paths found
}







// Method 2
void dfs(string word, vector<string> &seq, unordered_map<string, int> &mpp, vector<vector<string>> &ans, string start)
{
    // Base case: if we reach the start word, store the sequence in reverse
    if (word == start)
    {
        vector<string> temp = seq;
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        return;
    }

    int steps = mpp[word]; // Get the current depth/step of this word in the BFS layer

    // Try all possible transformations by changing one letter at a time
    for (int i = 0; i < word.size(); i++)
    {
        char original = word[i];
        for (char c = 'a'; c <= 'z'; c++)
        {
            word[i] = c;
            if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1)
            {
                // If this transformation exists in the map and it's part of the shortest path
                seq.push_back(word);
                dfs(word, seq, mpp, ans, start); // Recursively explore
                seq.pop_back();                  // Backtrack
            }
        }
        word[i] = original; // Revert the letter back
    }
}

vector<vector<string>> solve(string start, vector<string> &wordList, string target)
{
    vector<vector<string>> ans;

    unordered_set<string> st(wordList.begin(), wordList.end());
    unordered_map<string, int> mpp; // Map to store the shortest path step for each word
    queue<string> q;

    // Edge case: if the target is not in the word list
    if (st.find(target) == st.end())
        return ans;

    q.push(start);
    mpp[start] = 1;
    st.erase(start); // Avoid revisiting the start word

    // Perform BFS to populate the shortest paths to each word




    {
        string word = q.front();
        int steps = mpp[word];
        q.pop();

        if (word == target)
            break; // If we've reached the target, stop BFS

        // Try all possible one-letter transformations
        for (int i = 0; i < word.size(); i++){
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (st.find(word) != st.end())
                {
                    q.push(word);
                    mpp[word] = steps + 1; // Mark this word with its level in BFS
                    st.erase(word);        // Remove from the set to avoid revisiting
                }
            }
            word[i] = original; // Revert the letter back
        }
    }

    // If BFS completed without finding the target, return an empty answer
    if (mpp.find(target) == mpp.end())
        return ans;

    vector<string> seq = {target};
    dfs(target, seq, mpp, ans, start); // Perform DFS to retrieve all paths

    return ans;
}

    int main()
{
    // Predefined inputs
    string start = "hit";
    string target = "cog";

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    // Call the solve function
    vector<vector<string>> result = solve(start, wordList, target);

    // Print the results
    if (result.empty())
    {
        cout << "No transformation sequence found!" << endl;
    }
    else
    {
        cout << "Transformation sequences are: " << endl;
        for (const auto &seq : result)
        {
            for (const auto &word : seq)
            {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
