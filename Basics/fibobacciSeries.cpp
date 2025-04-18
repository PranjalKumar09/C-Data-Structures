#include<iostream>
using namespace std;

/*
recursion series don,t give sum but (n+1)th term so always search nth term
so always call  fibonacci series as num-1  with 2 base condtions 0 and 1

num  < 1 negative number
cout << 0
if num not less  than 2  cout << 1
for loop 2 to num


*/

/*
https://leetcode.com/problems/fibonacci-number/submissions/

class Solution {
public:
    int fib(int n) {
        if (n <2 )
            return n;
        int last = 1, last_second = 0 ,  sum;
        for (int i = 2; i <= n ; i++){
            sum = last + last_second;
            last_second = last;
            last = sum;
        }
        return sum;
    }
};

https://www.codingninjas.com/studio/problems/print-fibonacci-series_7421617?leftPanelTabValue=SUBMISSION
int fib(int n) {
        if (n <2 )
            return n;
        int last = 1, last_second = 0 ,  sum;
        for (int i = 2; i <= n ; i++){
            sum = last + last_second;
            last_second = last;
            last = sum;
        }
        return sum;
    }


vector<int> generateFibonacciNumbers(int n) {
    vector<int> Answer;
    
    for (int i = 0 ; i < n ; i++)
        Answer.push_back(fib(i));
    return Answer;
}


*/

int fiboconcci_series(int num){
    if (num == 0 || num == 1)
       return num;
    return fiboconcci_series(num -1 )  + fiboconcci_series(num-2);

}

int fiboconcci_series_memoryization(int num , int fibro_data[]){//pass of refrecnce need size of array thats why we cant pass
    if (num <=1)
        return num;
    if (fibro_data[num] != 0)
        return fibro_data[num];
    return fiboconcci_series_memoryization(num-1, fibro_data) + fiboconcci_series_memoryization(num-2, fibro_data);
}

int main(){
    //Straighforwar solution
    int num , last_second = 0, last = 1;
    cout << "Enter the number: ";
    cin >> num;
    cout << endl;
    if (num < 0){
        cout <<  "Number should  be postive";
        return 0;}
    int sum = last_second + last;
    cout <<0 <<" ";
    if (!num<2)
        cout<<"1 ";
    for (int i = 2; i < num; i++){
        sum = last +last_second;
        cout << sum << " ";
        last_second = last;
        last = sum;}
     
    cout << endl <<  fiboconcci_series(num-1) << endl;

    // Method 3
    int fibro_data[num] = {0};
    cout << fiboconcci_series_memoryization(num -1 , fibro_data);

    return 0;
}