#include <bits/stdc++.h>
using namespace std;

/*Alien Directory
    =====================

The problem is to determine the order of characters in an alien language based on a list of words that are sorted according to the alien dictionary's order. Given multiple words and the number of unique characters (K), the task is to deduce the sequence of characters (alphabet order) in this unknown language by analyzing the relative order of characters in adjacent words.


    i/p: No of string, strings
        K -> No of alphabet


    baa
    abcd
    abca
    cab
    cad

    o/p: alien order -> bdac

    TC: O(N*M)      -> Topological sort
    SC: O(2K)+O(2K) -> Distance or array


*/
vector<int> topoSort(int K, vector<int> adj[])
{
    vector<int> inDegree(K, 0);
    vector<int> topo;

    // Calculate in-degree of each node
    for (int i = 0; i < K; i++)
        for (int neighbor : adj[i])
            inDegree[neighbor]++;
        
    

    // Use a queue for BFS
    queue<int> q;
    for (int i = 0; i < K; i++)
        if (inDegree[i] == 0)
            q.push(i);
        
    

    // Process nodes in topological order
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
            
        }
    }

    return topo;
}

int main()
{
    // Pre-input: List of words and number of unique alphabets (K)
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    int K = 4; // Number of unique alphabets (for this example)

    // Construct the adjacency list
    vector<int> adj[K];
    int n = words.size();

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = words[i], s2 = words[i + 1];
        for (int j = 0; j < min(s1.length(), s2.length()); j++)
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        
    }

    // Perform topological sort to find alien order
    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for (auto it : topo)
        ans += char(it + 'a');
    

    // Output the alien order
    cout << "Alien Order: " << ans << endl;

    return 0;
}
