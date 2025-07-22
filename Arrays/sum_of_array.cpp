#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void display_as_sum(vector<int> &arr){
    reverse(arr.begin(), arr.end());
    int size = arr.size();
    for (int i = 0 ; i < size  ; i ++)
        cout <<  arr[i] ;
    
}


void reverse(vector<int>& answer){
    for(int i=0;i<answer.size()/2;i++){
        swap(answer[i],answer[answer.size()-1-i]);
    }
}

vector<int> sum_of_arrays(vector<int> &arr1 , vector<int> &arr2){
    int size1 = arr1.size() , size2 = arr2.size();
    int i = size1-1 , j = size2-1, carry = 0;
    vector<int> answer;
    while(i >= 0 && j >= 0){
        int sum = arr1[i--] + arr2[j--] + carry;
        answer.push_back(sum % 10);
        carry = sum /10;
    }    
    while(i >= 0){
        int sum = arr1[i--] + carry;
        answer.push_back(sum % 10);
        carry = sum /10;
    }
    while(j >=0){
        int sum = arr2[j--] + carry;
        answer.push_back(sum % 10);
        carry = sum /10;
    }
    if(carry!= 0){
        answer.push_back(carry);
    }
    return answer;
}

int main(){
    cout << endl; 

    vector<int> arr1 = {7, 1, 4, 7, 8, 5, 9, 4, 2, 3}; // 7147859423
    vector<int> arr2 = {5, 2, 3, 8, 9, 7, 4, 2, 6, 0}; //5238974260
    vector<int> ans = sum_of_arrays(arr1,arr2);
  
    display_as_sum(ans); 
    
    cout << endl;
    return 0;
}

