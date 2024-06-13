/* 
Catlon -> (^(2n) C (n)) / (n+1)  => (2n)!/(n! * n! * (n+1))
which is equal to CiCn 





 */


#include <iostream>
using namespace std;


int factorial (int num){
    if (num < 2) return 1;
    int ans = 1 ; 
    for (int i = 2; i <= num ; i++) ans *= i ;
    return ans;
}
int formula_based(int num){
    return factorial(num*2) / (factorial(num) * factorial(num) * (num + 1)) ;
}

int reursion_way (int num){
    if (num < 2) return 1;
    int ans = 0;
    for (int i  = 0 ; i < num ; i++) ans += reursion_way(i) * reursion_way( num - 1 - i) ;
    return ans ; 
}




int main(){
    int num = 4;
    cout << formula_based(num) << " "  << reursion_way(num) << endl;
}