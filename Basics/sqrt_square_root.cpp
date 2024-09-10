#include<iostream>

using namespace std;

double square_root_sqrt(int num , int precision){   
    if (num < 0 ) return -1; // if num is negative then return -1
    if (num == 0) return 0;

    
    int left = 1 , right = num - 1  , mid;
    while(left < right){ // this loop will find integer answer
        // mid * mid shoule equal or close to number, let mid*mid = NUM
        // if NUM  is greater than num then decrease left
        // if NUM is less than number then increase left 
        // if equal break loop
        mid = left +( right - left)/2;
        if (mid * mid  == num) break;
        mid * mid > num ? right = mid - 1 : left = mid + 1;} 
    double factor = 1  , ans = mid;
    for (int i = 0 ; i < precision ; i++){
        factor/=10;
        for(double j = ans ; j * j  < num ; j= j+ factor)
            ans = j;}
    return ans;}



int main(){
    cout << endl;


    int num, precision; // asking user number and precision 
    // precision should be less than 5-6 for better performance
    // number should not be negative (added this already)

    cout << " Enter the number : " ;
    cin >> num; cout << endl;

    cout << "Enter the precision : " ;
    cin >> precision; cout << endl;

\

    // displaying the output

    double ans = square_root_sqrt(num , precision); // called function

	if (ans == -1 ){ // negative root not exist 
        cout << "Number should be more than zero " << endl;
        return -1;}
    cout << "The square root of the number is " << ans ;
    

    cout << endl;
    return 0;
}