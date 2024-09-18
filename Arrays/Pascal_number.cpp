/* 
miniimum no of comparisons is 3n/2 - 2;
 */
#include<iostream>
#include<vector>
#include<utility> // for std::pair

using namespace std;

int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

void printPascal(int n)
{
    // Iterate through every line and
    // print entries in it
    for (int line = 0; line < n; line++) {
        // Every line has number of
        // integers equal to line
        // number
        for (int i = 0; i <= line; i++)
            cout << " " << binomialCoeff(line, i);
        cout << endl;
    }
}

void betterPrintPascal(float n){
    for (int i = 0; i < n; i++) {
        float res = 1;
        for (int j = 1 ; j <= i+1 ; j++)
            {cout << res << " " ;
            res *= (1.0+i-j)/j;}
        cout << endl; 
    }
}

int main(){

    betterPrintPascal(6) ;    
    return 0;
}
