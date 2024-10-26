#include <iostream>
using namespace std;

int ClimbingStairs(int num){ // runtime error
    if (num = 0 || num == 1)
        return 1;
    return ClimbingStairs(num-1) + ClimbingStairs(num-2);
}
int ClimbingStairs2(int num){ // doing memorization
    int arr[num] = {0};
    arr[0] = 1 ;arr[1] = 1; 
    for (int i = 2; i < num ; i++)
        arr[i] = arr[i-1] + arr[i-2];
    return arr[num-1] + arr[num-2];}

int ClimbingStairs3(int num){ // doing memorization
    if (num  < 2)    return 1;
    int prev2 = 1, prev = 1;
    for (int i = 2; i < num ; i++)
        int ans = prev2 + prev;
    

    return arr[num-1] + arr[num-2];}




int main(){
    int num;
    cout << "Enter the number ";
    cin >> num; cout << endl;
    cout<< " No of stairs are " << ClimbingStairs2(num);



    return 0;
}