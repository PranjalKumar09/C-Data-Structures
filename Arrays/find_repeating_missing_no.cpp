/* 


Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.


Brute Force >   TC => O(2N)        ->  SC => O(N)
Reapted ->      from 0 to size -1  ->  NO break  ->     if(count[array[i] - 1]    
Duplicate ->    from 0 to size -1  ->  break     ->     if (count[i] == 0)



among all maths method is best 

 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair <int, int>  Brute_Force(vector<int> &array){

    int repeated =  -1 , missed = -1 ;
    vector<bool> count (array.size () , 0);
    
    for(int i=0; i< array.size() ;i++)
        {
            if(count[array[i] - 1])
                repeated = array[i];
            else
                count[array[i] - 1] = 1;
        }
    
    for (int i = 0; i< count.size(); i++){
        if (count[i] == 0){
            missed = i+1;
            break;
        }
    }


    return make_pair(repeated , missed);
}

pair<int, int> Math_Method(vector<int> &array) {
    int size = array.size();
    int sum_n = (size * (size + 1)) / 2;
    int square_n = ((size * (size + 1) * (2 * size + 1))) / 6;
    int sum = 0, square = 0;
    
    for (int i = 0; i < size; ++i) {
        sum += array[i];
        square += array[i] * array[i];
    }
    
    // sum = sum_n - missing + repeated
    // square = square_n - missing^2 + repeated^2
    
    int val1 = sum_n - sum;
    int val2 = square_n - square;
    int val3 = val2 / val1;  // val3 = missing + repeated
    
    int missed = (val3 + val1) / 2;
    int repeated = val3 - missed;
    
    return make_pair(repeated, missed);
}

pair<int, int> XOR_Method(vector<int> &array) {
    int n = array.size(); // size of the array

    int xor_result = 0;
    // let assume array = {1, 2, 3, 3, 5}
    // Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xor_result ^= array[i];
        xor_result ^= (i + 1);
        cout << i << " " << xor_result << endl;
    }
    // xor_result = missing ^ repeated      xor_result = 3 ^ 4 = (111)   7

    // Step 2: Find the rightmost set bit in xor_result:
    int rightmost_set_bit = (xor_result & ~(xor_result - 1)); // 7 & ~6 =>  111  & 001    (1 = 001)       =  1   

    // Step 3: Group the numbers:
    int group_zero = 0;
    int group_one = 0;
    for (int i = 0; i < n; i++) {
        // Part of 1 group:
        if ((array[i] & rightmost_set_bit) != 0) //  groupi => 1 ^ 3  ^ 3 ^ 5 
            group_one ^= array[i];
        // Part of 0 group:
        else
            group_zero ^= array[i]; // group0 = 0 ^ 2 
    }

    for (int i = 1; i <= n; i++) {
        // Part of 1 group:
        if ((i & rightmost_set_bit) != 0) // group1 = 1 ^ 3 ^  ^ 3 ^ 5 ^ 1 ^ 3 ^ 5  = 3
            group_one ^= i;
        // Part of 0 group:
        else
            group_zero ^= i; // group 0 =  0 ^ 2 ^ 2 ^ 4 = 4  
    }

    // Last step: Identify the numbers:
    int zero_count = 0;
    for (int i = 0; i < n; i++)
        if (array[i] == group_zero) zero_count++; 

    if (zero_count == 2) return make_pair(group_zero, group_one);
    return make_pair(group_one, group_zero);
}


int main(){
    cout << endl;

    vector<int> arr =  {1,2,3,3,5};

    pair <int , int> ans = XOR_Method(arr);
    cout << ans.first << " " << ans.second << endl;

    
    
    cout << endl;
    return 0;
}