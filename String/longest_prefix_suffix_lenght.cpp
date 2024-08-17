/*  
in brute force check ionly upto half not complete string
and start1 is fixed 0 while start depends on j of nested loop 

in brute force strat2  == str.length() because becase start2 will increased in prvious while 
similarly start1 taken not start + 1 because start2 value is inceased in while already


 */

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int brute_force_lonegest_prefix_suffix(string str){
    int count = 0 ; 
    for (int i =  0; i < str.length()/2; i++) {
        for (int j = str.length()/2; j < str.length(); j++) {
         int start1 = 0 , start2 = j ; 
         while ( start2 < str.length()) {
            if (str[start1] == str[start2] ){ start1++; start2++;}
            else break;
         }
         if (str.length()  == start2) count = max (count , start1 ); 
 }}
 return count;}

 int KMP_Method_lonegest_prefix_suffix(string str){
    int j = 0, i = 1;
    vector<int> kmp(str.length(), 0);
    while( i < str.length()){
        if (str[i] == str[j] ) {
            kmp[i] = j+1;
            i++;j++;        }
        else {
            if (j!= 0) j = kmp[j-1];
            else {kmp[i] = 0; i++;}        }
            }
    return kmp.back() ; 
 }

 int main(){

    cout << endl ;

    string str = "abcdjkfnabcd";
    cout << brute_force_lonegest_prefix_suffix(str) << endl << KMP_Method_lonegest_prefix_suffix(str);

    cout << endl ;

    return 0;
}

 