/* Note something

In this question remember it is type of twisted logic if more higher the tree it will save ecologically, so we don't have to decrease high but we have to do low = mid + 1 if is possible

Also note that returing on low and high will usually low , high , low - 1 , high + 1 */

#include<iostream>
#include<vector>
#include<algorithm>




using namespace std;

bool is_possible(vector<int> &trees_height , int woods_wanted , int height){
    int woods_collected = 0;
    for (int i = 0; i < trees_height.size(); i++){
        if (trees_height[i] > height) woods_collected+=(trees_height[i]-height);
        if (woods_collected >= woods_wanted ) return true;}
        return false;
    
    }


int EKO_SPOJ(vector<int> &trees_height , int woods_wanted){

    sort(trees_height.begin(), trees_height.end());

    int low = 0 , high = 0;

    for (int i = 0; i < trees_height.size(); i++) high = max(high, trees_height[i]);

    while (low <= high) {
        // cout << "low: " << low << " , high : "  << high << endl;
        int mid = low + (high - low) / 2;
        if (is_possible(trees_height , woods_wanted , mid)) low = mid + 1;
        else high = mid-1;}
    return low-1;}
int main(){
    cout << endl;

    int woods_wanted = 20;
    vector<int> trees_heights = {4,42,40,26,46};

    cout << EKO_SPOJ(trees_heights, woods_wanted);
    
    
    cout << endl;
    return 0;
}