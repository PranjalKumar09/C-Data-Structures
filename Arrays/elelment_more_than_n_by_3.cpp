
/* 
Brute Force Method -> 


first loop will run from 0 to arr.size()*2/3 +1 
this optimize because upto ther only element can appear more than n/3 times

count initiliase

second nested loop will run from i+1 to arr.size() 

then check if arr[i] == arr[j] then count++

then if count == arr.size()/3 and (temp size == 0  or arr[current_element] not equal to  last element of temp then push current elelment to temp array and break TOO]]


then check at end of first loop that whether temp size is 2 if then break because after that no further loop will exexcuted 

Time Complexity: O(N2)

Space Complexity: O(1)






Hashing Method->

Time Complexity: O(N*logN)

Space Complexity: O(N) 






OPTIMIZED METHOD (MOORE'S VOTING ALGORITHM)
Time Complexity: O(N) + O(N)
Space Complexity: O(1)

We know that the maximum possible number of elements in the answer is 2.

In this method, four variables are chosen:
- ele1, ele2: to store both potential majority elements (initialized with INT_MIN)
- count1, count2: to count occurrences of the respective elements (initialized with 0)

In the first loop, it iterates through the array:
- If count1 is 0 and ele1 is not equal to the current element, set count1 to 1 and set ele1 to the current element.
- Else if count2 is 0 and ele2 is not equal to the current element, set count2 to 1 and set ele2 to the current element.
- Else if ele1 is equal to the current element, increment count1.
- Else if ele2 is equal to the current element, increment count2.
- If none of the above conditions are met, decrement both count1 and count2.

After the first loop, ele1 and ele2 store the potential majority elements.
Reset count1 and count2 to 0 and re-count the occurrences of ele1 and ele2 by iterating through the array again:
- If the current element is equal to ele1, increment count1.
- Else if the current element is equal to ele2, increment count2.

Finally, check whether the counts of ele1 and ele2 are greater than the threshold (array size divided by 3).
If so, push the respective elements into the result vector.



 */

#include <iostream>
#include <vector> 
#include <unordered_map>
#include <climits>

using namespace std;



vector<int> brute_force(vector<int> &arr) {
    vector<int> temp;
    int threshold = 1 + arr.size() / 3;

    // First loop runs from 0 to arr.size()*2/3 + 1
    for (int i = 0; i < (arr.size() * 2 / 3) + 1; i++) {
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++) {
            // cout  " count = " << count << " " << arr[j] << endl;
            if (arr[i] == arr[j])
                count++;

            // Check if count reaches arr.size()/3
            if (count == threshold) {
                // If temp is empty or arr[j] is not equal to the last element of temp
                if (temp.empty() || arr[j] != temp.back()) {
                    temp.push_back(arr[j]);
                }
                break;
            }
        }
        // If temp size is 2, then break
        if (temp.size() == 2)
            break;
    }
    return temp;
}


vector<int> better(vector<int> &arr){
    vector<int> temp;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]]++;
    for (auto current : mp){
        if (current.second >= arr.size()/3)
            temp.push_back(current.first);
    }
    return temp;
}

vector<int> Optimized_moore_voting_algo(vector<int> &arr){
    int ele1 = INT_MIN  , ele2 = INT_MIN , cout_1 = 0 , cout_2 = 0;
    for (int i = 0 ; i < arr.size(); i++){
        if (cout_1 == 0 && ele1 != arr[i]){
            cout_1 = 1;
            ele1 = arr[i];
        }
        else if (cout_2 == 0 && ele2!= arr[i]){
            cout_2 = 1;
            ele2 = arr[i];
        }
        else if (ele1 == arr[i])cout_1++;
        else if (ele2 == arr[i])cout_2++;
        else {cout_1-- ; cout_2--;}
    }
    cout_1 = cout_2 = 0;
    for (int i = 0 ; i < arr.size() ; i++){
        if (ele1 == arr[i]) cout_1++;
        if (ele2 == arr[i]) cout_2++;
    }


    int threshold = 1 + arr.size() / 3;
    vector<int> temp;
    if (cout_1 >= threshold) temp.push_back(ele1);
    if (cout_2 >= threshold) temp.push_back(ele2);
    

    return temp;
    
    }







int main(){
    vector<int> arr =  {7, 7, 7, 3, 4, 4, 4, 5};
    vector<int> temp = Optimized_moore_voting_algo(arr);
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl; 
    
    return 0;
}