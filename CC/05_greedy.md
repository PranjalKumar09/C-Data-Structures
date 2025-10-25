948. Bag of Tokens
    We have to maximize the score
    
    score = 0
    Power >= token[i]
        powe-+=token[i]
        score += 1

    score >= 1
        power+=token[i]
        score -= 1


    greedy
        sort

881. Boats to Save People
    sort as usual
    while start<= end
    poeple[start] + people[end] <= limit

    normal greedy



1328. Break a Palindrome
    lexigoraphically small -> so change from start

    converrt to a , any upto n/2,, 
        if not matched then we can change last to b

    for 1 length string, return "" , as 1 character will always palindrome



991. Broken Calculator
    start from target


1578. Minimum Time to Make Rope Colorful
        maintainng prev & curr

         time += min(prev , curr)
        prev = max(prev,curr); ,(0for new ballon)
    #include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev = neededTime[0], n = colors.length(), time = 0;
        
        for (int i = 1; i < n; i++){
            if (colors[i] != colors[i-1]) prev = 0;


            time += min(prev, neededTime[i]);
            prev = max(neededTime[i], prev);
            
        }
        
        return time;
    }
};


2136. Earliest Possible Day of Full Bloom
    
    Approach
        Plant one seed on one day

        
        sort B  = <Grow, Plant>
        then max in above array as B.second + idx
        this is ans



class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i++)
            arr.push_back({growTime[i], plantTime[i]});
        
        // Sort by growTime descending (longest grow first)
        sort(arr.rbegin(), arr.rend());
        
        int curPlant = 0; // total days spent planting
        int ans = 0;
        
        for (auto& [g, p] : arr) {
            curPlant += p;
            ans = max(ans, curPlant + g); // bloom day for this flower
        }
        
        return ans;
    }
};


2131. Longest Palindrome by Concatenating Two Letter Words
    we will store in map <string, freq>
    
    center if freq = 1, and string = rev(string)

    if string = rev(string)
        if freq>=2 , ans+=4..
        if freq = 1 & centerUsed = false  , ans+=2..

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> um;
        for (auto it: words)
            um[it]++;
        
        int ans = 0;
        bool used = 0;
        for (auto& it: um){
            string rev = it.first;
            reverse(begin(rev), end(rev));
            if (it.first != rev){
                if (it.second > 0 && um[rev] > 0){
                    ans += min(it.second , um[rev])*4;
                    um[rev] =0;
                }}
            else {
                if (it.second >=2){
                    ans += (it.second/2)*2*2;
                    um[it.first] = it.second%2; 
                }
                if (!used && um[it.first] == 1){
                    ans += 2;
                    used = 1;
                    }                
                }
                // um[it.first] = 0;
                cout <<it.first << ans << endl;
            }
                
        return ans;
    }
};



class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> um;
        for (auto &w : words) um[w]++;

        int ans = 0;
        bool usedMiddle = false;

        for (auto &p : um) {
            const string &w = p.first;
            int cnt = p.second;
            string rev = w;
            reverse(rev.begin(), rev.end());

            if (w < rev) {               // ensure one direction only
                if (um.count(rev)) {
                    int pairs = min(cnt, um.at(rev));
                    ans += pairs * 4;
                }
            } else if (w == rev) {
                ans += (cnt / 2) * 4;
                if (cnt % 2 == 1) usedMiddle = true;
            }
            // if w > rev we skip because the pair handled when visiting rev
        }

        if (usedMiddle) ans += 2;
        return ans;
    }
};



this problem tells thzat, we shouldnt modify idrectly in unordered_map, while iterating





1323. Maximum 69 Number
    approach 1
        convert to string, then proceed
    apporach 2
        we are adding 3, or 30, or 300,, like this, , we will do this upto end