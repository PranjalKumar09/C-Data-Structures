#include <iostream>
using namespace std;

double myPow(double x , int n){
    double ans = 1.0 ; 
    long long nl = n;
    if (nl < 0) nl = -1*n*n;
    while (nl)
    {
        if (nl % 2){ ans *= x;
        nl -=1 ;}
        else {
            nl /= 2;
            x *=x ;
        if (n<0) ans = (double)(1.0)/(double)(ans);
        }
    }
    return ans;
    
}

double myPowRecursion(double x , int n){
    if (n == 0) return 1.0;
    if (n == 1) return x;
    double ans = myPowRecursion(x, n/2);
    if (n%2 == 0) return ans * ans ;
    else return ans * ans * x;
}

int main() {


    cout << myPow(32 , 3) << endl << myPowRecursion(32,3);


}