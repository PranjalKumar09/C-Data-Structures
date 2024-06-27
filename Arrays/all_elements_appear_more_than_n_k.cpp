/* 


Time Complexity: O(n*logn), as we are sorting the array.

Space Complexity:- O(1)





Using Map
 
Time Complexity: 

O(n)- as we are traversing through the array only once.

Space Complexity:

O(n)- if all the elements are unique in the array so every element will take space.

 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>



using namespace std;


void display (vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> brute_force(vector<int> &arr , int k){
    vector<int> temp; 
    for (int i = 0; i < arr.size() - 1; i++) {
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++) 
            if (arr[i] == arr[j]) 
                count += 1;
        if (count >= (arr.size()/k) ) temp.push_back(arr[i]) ;
        
    }
    return temp;
}


vector<int> better(vector<int> &arr , int k ){
    vector<int> temp;
    int value = arr.size()/k;
    unordered_map <int , int> mp;
    for (int i = 0; i < arr.size() ; i++)
        mp[arr[i]]++;
    for (auto current:mp)
        if (current.second >= arr.size()/k)
            temp.push_back(current.first);
    return temp;

    
}


int main(){
    vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3} ; 
    int k = 4;
    vector<int> result = better(arr , k);
    display(result); 
    cout << endl;
    return 0;
}