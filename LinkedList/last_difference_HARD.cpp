/* 

https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/

 */
class Solution {
public:
    int minChanges(vector<int>& v,int k){
        int n=v.size();
        vector<int>diff(k+1,0),pos(k+1,0);
        for(int i=0;i<n/2;i++){
            int cur=abs(v[i]-v[n-i-1]);
						diff[cur]++;
            int mx=max({v[i],v[n-i-1],k-v[i],k-v[n-i-1]});
            pos[mx]++;
        }
        int ans=1e9;
        int tot=n/2,not_pos=0;
        for(int i=0;i<=k;i++){
            ans=min(ans,(2*not_pos) + tot - diff[i]);
            tot-=pos[i];
            not_pos+=pos[i];
        }
        return ans;
    }
};