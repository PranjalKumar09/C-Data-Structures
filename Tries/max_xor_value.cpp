#include <bits/stdc++.h>
using namespace std;

/* 
Max XOR Queries
===============

Cant XOR with greater than element given list ARR consists of N non -ve intergers. You are also fiven list of queries consisting of M quereise where ith query is list of two non-ve intergers Xi, Ai
Queries  ip[i] = [Xi , Ai]
        Xi -> max bit 

 Input: Given Array: [3, 10, 5, 25, 2, 8], Queries: [(0, 1), (1, 2), (0, 3), (3, 3)] 

 Output:[-1, 3, 3, 1]
 
 Explanation: Result of Max XOR Queries:

Query (0,1):

We need to find the maximum XOR value of 0 with any integer less than or equal to 1 in the array.   
The integers in the array less than or equal to 1 are: None.
Since there are no integers less than or equal to 1 in the array, the answer is -1.

    Query (1, 2):    
We need to find the maximum XOR value of 1 with any integer less than or equal to 2 in the array.
The integers in the array less than or equal to 2 are: 2.
The XOR value is : 1 XOR 2 = 3.
The maximum XOR value is 3.

    Query (0, 3):    
We need to find the maximum XOR value of 0 with any integer less than or equal to 3 in the array.
The integers in the array less than or equal to 3 are: 3, 2.
The XOR values are: 0 XOR 3 = 3, 0 XOR 2 = 2
The maximum XOR value is 3.

    Query (3, 3):    
We need to find the maximum XOR value of 3 with any integer less than or equal to 3 in the array.
The integers in the array less than or equal to 3 are: 3, 2.
The XOR values are: 3 XOR 3 = 0, 3 XOR 2 = 1
The maximum XOR value is 1.


i/p : vector<int> &arr, vector<vector<int> > &queries

    Method 1 : B.F.
        TC = O(Q*N)
        SC = O(1)
        

    Method 2 : Optimal
        TC = O(M)+O(M log M) + O (32)(M+N)
            O(M)-> for creating offline occirs
            O(M log M)-> for sorting
            O(32)(M+N)-> for inserting  
            
        SC = O(32*N)


     */

void print_arr(vector<int> &arr){
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " " ;
    cout << endl;
}

vector<int> solve1(vector<int> &arr, vector<vector<int> > &queries){
    int n = arr.size();
    int m = queries.size();
    vector<int> ans(m,-1);
    for (int i = 0; i <  m; i++){
        for (int j = 0; j < n; j++)
            if (arr[j] <= queries[i][1])
                ans[i] = max(ans[i], queries[i][0]^arr[j]);
    }
    return ans;
}

class TrieNode {
public:
    TrieNode* children[2];
    
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
    
    bool containsKey(int bit) {
        return children[bit];
    }
    
    TrieNode* get(int bit) {
        return children[bit];
    }
    
    void put(int &bit, TrieNode *node) {
        children[bit] = node;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) 
                node->put(bit, new TrieNode());
            
            node = node->get(bit);
        }
    }

    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) { // due to xor property we choosing oopposite 
                maxXOR = maxXOR | (1 << i);
                node = node->get(1 - bit);
            } else 
                node = node->get(bit);
            
        }
        return maxXOR;
    }
};
vector<int> solve2(vector<int> &arr, vector<vector<int> > &queries) {
    int n = arr.size();
    int m = queries.size();

    sort(arr.begin(), arr.end());
    vector < pair <int, pair<int,int> > > OQ; // offline Queries;
    
    for(int  i = 0; i < m ; i++) 
        OQ.push_back({queries[i][1], {queries[i][0] , i}});

    sort(OQ.begin(), OQ.end());

    int i = 0;

    Trie* trie = new Trie();
    
    vector<int> ans(m,-1);
    for(auto &it : OQ){
        while(i<n && arr[i] <= it.first)
            trie->insert(arr[i++]);
        
        if (i)
            ans[it.second.second] = trie->findMaxXOR(it.second.first);
    }

    
    return ans;}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};

    // XOR queries
    vector<vector<int>> queries = {{0, 1},{ 1, 2},{ 0, 3},{ 3, 3} };
    
    vector <int> ans1 = solve1(nums, queries); 
    vector <int> ans2 = solve2(nums, queries);

    print_arr(ans1);
    print_arr(ans2);

    return 0;
}