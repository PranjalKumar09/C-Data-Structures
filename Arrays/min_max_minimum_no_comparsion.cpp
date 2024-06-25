/* 
miniimum no of comparisons is 3n/2 - 2;
 */
#include<iostream>
#include<vector>
#include<utility> // for std::pair

using namespace std;

pair<int, int> solution(vector<int>& arr){

    int count = 0 , maxi = 0 , mini = 0;
    if (arr.size()  < 2) return make_pair(0, 0);
    if (arr.size() % 2 == 0) {
        if (arr[0] > arr[1]){
            maxi = arr[0];
            mini = arr[1];
        }
        else{
            maxi = arr[1];
            mini = arr[0];
            count = 2;
        }
    }
    while( count < arr.size() -1 ){
        if (arr[count] > arr[count+1]){
            if (arr[count] >  maxi)maxi = arr[count];
            if (arr[count + 1] < mini)mini = arr[count+1];
        }
        else{
            if (arr[count + 1] > maxi)maxi = arr[count+1];
            if (arr[count] < mini)mini = arr[count];
        }
        count += 2;
    }
    return make_pair(mini, maxi);
}

int main(){
    cout << endl;
    vector<int> arr = {0,1,2,3,4,5,6,7};

    auto result = solution(arr);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;
    cout << endl;
    return 0;
}
