#include <iostream>

using namespace std;

void AllDevisors(int num){
    for (int i = 1; i < num+1; i++){
        if (num % i == 0 ) cout << " " << i ;
}}

int main(){
    int num;
    cout << " Enter the number : " ;
    cin >> num;

    cout << "All divisor of the number are ";
    
    AllDevisors(num);

    cout << endl ; 
    return 0;
}