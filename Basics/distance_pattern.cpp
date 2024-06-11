#include<iostream>
using namespace std;
int mini(int a, int b , int c , int d){
    int maxi = a;
    if (b<maxi)
        maxi = b;
    if (c<maxi)    maxi = c;
    if (d<maxi)    maxi = d;
    return maxi;
}
int main(){
    int num;
    cout << "Enter the number : ";
    cin >> num;
    for (int i = 0 ; i < 2*num-1 ;  i++){
        for (int  j =0 ; j < 2*num-1 ;  j++)
            cout << mini(i , j ,(2*num -2)- i, (2*num-2-j));
        cout << endl;
    }
}

