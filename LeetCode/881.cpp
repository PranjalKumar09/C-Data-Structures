#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int  boats = 0 , end, start = 0, sum = 0;
        sort(people.begin(), people.end());
        for (end = people.size() - 1; end >= 0 && people[end] >= limit; end--) boats++;

        while(start > end){
            if (people[start] +people[end] + sum < limit){
            sum += people[start] + people[end];
            start++;
            end--;}
            else if (sum + people[end] < limit)
            sum += people[end--];
            else if (sum + people[start] < limit)
            sum += people[start++];
            else {
            sum = 0;
            boats++;}
            cout << "start: " << start << "  end: " << end << "  boat: " << boats << "  sum: "  << sum << endl;
        }
        return boats+1;
        
                
    }
};


int main(){

}