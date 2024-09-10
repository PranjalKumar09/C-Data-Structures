#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

void Display(vector<int> arr){
    int size = arr.size();
    cout << "[ "; 
    for (int i = 0 ; i < size -1 ; i++){
        cout << arr[i] << " , ";
    }
    cout << arr[size-1] << " ] " << endl; 
}



vector<int> Union_By_2_pointer_approach(int arr1[], int arr2[], int size1, int size2){
    vector<int> ans;
    int i  = 0 , j = 0;
    while (i < size1 && j < size2){
        if (arr1[i] <= arr2[j]){
            if (ans.size() == 0 || arr1[i] != ans.back())ans.push_back(arr1[i]);
            i++;}
        else {if (ans.size() == 0 || arr2[j] != ans.back())ans.push_back(arr2[j]);
        j++;}}
    while( i < size1){
        if (ans.size() == 0 || arr1[i] != ans.back()) ans.push_back(arr1[i]);
        i++;
    }
    while (j < size2){
        if (ans.size() == 0 || arr2[j] != ans.back()) ans.push_back(arr2[j]);
        j++;
    }
    return ans;

}



vector<int> Union_By_Set(int arr1[], int arr2[], int size1, int size2){
    set<int> By_Set;
    for (int i = 0 ; i < size1 ; i++)By_Set.insert(arr1[i]);
    for (int i = 0 ; i < size2 ; i++)By_Set.insert(arr2[i]);
    vector<int> result;
    for (const auto& element : By_Set)result.push_back(element);
    return result;
    
}


vector<int> Union_By_Unordered_Map(int arr1[], int arr2[], int size1, int size2){

    unordered_map<int, int> unionMap; // <element , frequency> (frequency max)
    for (int i = 0; i < size1; i++) unionMap[arr1[i]]++; 
    for (int i = 0; i < size2; i++) unionMap[arr2[i]]++;
    
    vector<int> arr_result ; 
    for (const auto&  element : unionMap) arr_result.push_back(element.first);
    return arr_result;
}

int main(){
    cout << endl;

    int arr1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 36, 38, 40}, arr2[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90};
    int size1 = sizeof(arr1)/sizeof(arr1[0]) , size2 = sizeof(arr2)/sizeof(arr2[0]) ; 

    //Method 1 By unordered map 
    
    vector<int> result_method1 = Union_By_Unordered_Map(arr1, arr2, size1, size2);
    Display(result_method1 );

    //Method 2 By Set
    vector<int> result_method2 = Union_By_Set(arr1, arr2, size1, size2);
    Display(result_method2 );

    //Method 3 by 2 pointer approach



    vector<int> result_method3 = Union_By_2_pointer_approach(arr1, arr2, size1, size2);
    Display(result_method3 );
    
    
    
    cout << endl;
    return 0;
}

