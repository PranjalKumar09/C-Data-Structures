#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/*
    For problems like finding elements that appear more than ⌊n/3⌋ times, instead of using a hash map, we can solve it with just four variables: two for storing the potential elements and two for their respective counts

*/

int bruteforce(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        int count = 1;
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] == arr[j])
                count++;}
        if (count > arr.size()/2) return arr[i];
   }
    return -1;
}

int hashing(vector<int> &arr){
    map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        if(mp[arr[i]] > arr.size()/2) return arr[i];
    }
    return -1;
}

int moore_voting_algorithm(vector<int> arr){
    int cnt = 0, el ; 
    for (int i=0;i<arr.size();i++){
        if (cnt == 0){
            el = arr[i];
            cnt = 1;}
        else if (el == arr[i])
            cnt++;
        else 
            cnt--;
    }
    cnt = 0 ; // checking if elelment is majorrty
    for (int i=0;i<arr.size();i++) if (arr[i] == el ) cnt++;
    if (cnt > arr.size()/2) return el;
    return -1;

}

int main(){
    cout << endl;
    
    vector <int> arr = {3,2,3 , 3, 1, 1, 1,2, 4,5,3};
    cout << bruteforce(arr) << endl;
    cout << hashing(arr) << endl;
    cout << moore_voting_algorithm(arr) << endl;



    cout << endl;
    return 0;
}