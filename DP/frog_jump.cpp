#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int frog_jump_by_recursion(vector<int>& hights , int num ){
    if (num == 0) return 0;
    if (num == 1) return abs(hights[0]-hights[1]);

    int first = frog_jump_by_recursion(hights , num-1) + abs(hights[num]-hights[num-1]) ;
    int second = frog_jump_by_recursion(hights , num-2) + abs(hights[num]-hights[num-2]) ;

    return min(first, second);
}

int frog_jump_by_memorization(vector<int>& hights , int num , vector<int>& memorization){
    if (memorization[num] != -1) return memorization[num];
    if (num == 0) return memorization[0];
    if (num == 1) {
        memorization[num] = abs(hights[0]-hights[1]); 
        return memorization[num];
    }

    int first = frog_jump_by_memorization(hights , num-1, memorization) + abs(hights[num]-hights[num-1]) ;
    int second = frog_jump_by_memorization(hights , num-2, memorization) + abs(hights[num]-hights[num-2]) ;

    memorization[num] = min(first, second);

    return min(first, second);


}
int frog_jump_by_tabulation(vector<int>& hights , int num ){ // this is dp approach
    vector<int> tmp(hights.size() , -1);
    tmp[0] = 0;
    for (int i = 0 ; i < num ; i++){
        if (i == 1){tmp[i] = abs(hights[1]-hights[0]);
        continue;}
        int first = tmp[i-1] + abs(hights[num]-hights[num-1]) ;
        int second = tmp[i-2] + abs(hights[num]-hights[num-2]) ;
        tmp[i] = min(first, second);
    }
    return tmp[num-1];
}

int main(){
    cout << endl;
    vector<int>  heights= {10,20,30,10};

    // cout << frog_jump_by_recursion(heights , heights.size()-1 ); // Method 1


    vector<int> memorization(heights.size() , -1); //For method 2
  
    // cout << frog_jump_by_memorization(heights, heights.size()-1,memorization); // Method 2 

    cout << frog_jump_by_tabulation(heights , heights.size()-1); // Method 3
    
    
    cout << endl;
    return 0;
}