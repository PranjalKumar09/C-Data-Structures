#include<iostream>

using namespace std;


//method 1 
int findNum(int n) {

    /* as number will 5 has 1 zero , 10 has 2 zero ,this process continues
     */
    int num = 1;
    int cnt = 0;
    while (true) {
        int temp = num;
        while (temp % 5 == 0) {
            cnt++;
            temp /= 5;
        }
        if (cnt >= n) {
            return num;
        }
        num++;
    }
}


 

// method 2

bool check (int mid , int n){
    int temp = mid , count = 0 , f = 5 ;
    while(f <= temp){
        count += temp/f ;  // this give how many 5 (f)  no divisible by temp factorial   
        f *= 5;    }
    return (count >= n);}

int findNum2(int n){
    if (n==1) return 5;
    int low = 0;
    int high = 5*n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid,n))  high = mid ;
        else   low = mid + 1;    }
    return low;
}




int main(){
    cout << endl;
    int num = 1;
    cout << findNum(num);

    
    cout << endl;
    return 0;
}