#include <bits/stdc++.h>
using namespace std;  
class Solution {
    string ring, key;
public:
    int solve(int ir , int ik){
        // bas3
        if (ik >= key.length()) return 0;

        int value  = INT_MAX;
        int length = ring.length(); // must take like this doing in less line give error

        for (int i = 0; i < ring.length() ; i++)
          if (ring[i] == key[ik])
            value = min(value , min( abs(i-ir) , length-abs(i-ir)) + 1 + solve(i, ik+1));
    return value;
            
    
    }
    int findRotateSteps(string ring, string key) {
        this->ring = ring, this->key = key;
        int ptr =  0;
        int index = 0;

        int n=ring.size();
        int m=key.size();

        return solve(0,0);      
    }
};
class Solution2 {
    string ring, key;
    vector <vector <int >> dp;
public:
    void printDp(){
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    int solve(int ir , int ik){
        // bas3
        if (ik >= key.length()) return 0;

        if (dp[ik][ir]!=-1) return dp[ik][ir];

        int value  = INT_MAX;
        int length = ring.length(); // must take like this doing in less line give error

        for (int i = 0; i < ring.length() ; i++){       cout << "ik = "<< ik << "  ir->" << ir << "  i->"<< i << "    ring[i]-> " << ring[i] << "      key[ik]->" << key[ik] << endl;
          if (ring[i] == key[ik])
            value = min(value , min( abs(i-ir) , length-abs(i-ir)) + 1 + solve(i, ik+1));
}   

    return dp[ik][ir]=value;
            
    
    }
    int findRotateSteps(string ring, string key) {
        dp.assign(key.size()+1 , vector<int> (ring.size()+1,-1));
        this->ring = ring, this->key = key;
        int ptr =  0;
        int index = 0;

        int n=ring.size();
        int m=key.size();

        return solve(0,0);      
    }
};

int main(){

    Solution2 s;
    cout<<s.findRotateSteps("caotmcaataijjxi", "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx")<<endl;
    return 0;
}