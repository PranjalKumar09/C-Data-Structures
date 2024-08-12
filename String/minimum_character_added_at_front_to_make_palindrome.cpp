/* 
Optimized ->  TC = O(N)        SC = O(1)


Note ->  we have to include words at first not at last


note j must not end to n but to n - 1
*/
#include <iostream>
#include<string>

using namespace std;

int optimized(string str){
    int i = 0 , j = str.length() - 1, res = 0 ;
    while ( i < j){
        if ( str[i] == str[j] ) { i++; j--; }
        else {
                res++;
                i = 0;
                j = str.length()  - 1 - res ; 
        }
        }
    return res;
    }
    

//we can also apply this logic in which whike checking plaidrome remove last character also increasing count if palindomr print count


bool isPalindrome(string str){
    int i = 0, j = str.length() - 1;
    while ( i < j){
        if ( str[i] == str[j] ) { i++; j--; }
        else    return false;
        
        }
    return true;
    
}

int brute_force(string str){
    int res = 0;
    while(!isPalindrome(str)){
        str.pop_back();
        res++;
    }
    return res;
}


int main(){
    cout << endl;

    string str = "ABCD" ;
    cout <<  optimized( str);

    cout << endl;
    return 0;
}