// NOT SOLVED PENDING  (solved but not optimized)!!!

/* 4  5 5 7 8 10 25
lower bound -> 7 => 7
lower bound -> 9 => 10
lower bound -> 26 => give pointer to next  (return something garbage value)
upper bound -> 5 => 7
upper bound -> 7 => 8
they both return location in array in vector they return iterator 
lower_bound(first, last, val) returns an iterator pointing to the first element in the range [first, last) that is not less than val 
upper_bound(first, last, val) returns an iterator pointing to the first element in the range [first, last) that is greater than val */

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool if_possible(vector<int> &arr , int first, int last){
    for (int i = first + 1 ; i < last ; i++) if ((arr[i] - arr[first])  == (arr[last] - arr[i]))    return true; 
    return false;
}

int Count_beautiful_triplets(vector<int> &arr ){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        int right= arr.size() - 1 ;
        while( i < right){
            if (if_possible(arr , i, right)) count+=1; 
            right--;
              
    }}
    return count;

}

int main(){
    cout << endl;   
    vector <int> arr = {1, 2, 3, 4, 5};
    cout << "Number of beautiful triplet is " << Count_beautiful_triplets(arr);
    
    
    
    cout << endl;
    return 0;

}   