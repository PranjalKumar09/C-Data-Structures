/* 
Input: s1 = "ab", s2 = "eidbaooo"
Output: True

Example 2
Input: s1 = "ab", s2 = "eidboaoo"
Output: False
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool check_permutation(string str1 , string str2){
    if (str1.length() < str2.length()) return false;
    int count1[26] = {0 } , count2[26] = {0} ;
    for (int i = 0; i < str1.length() && i ; i++) 
        count1[str1[i]- 'a']++;
    for (int i = 0; i < str2.length() && i ; i++) {
        if (count1[str1[i]- 'a'] < count2[str2[i]- 'a']) return false;
        count2[str2[i]- 'a']++;}
    return true;
    
    

    
    
}

int main(){
    cout << endl;
    
    string str = "heroshima"; //note only lowercase characters allowed
    string str2 = "sima";
    check_permutation(str,str2 ) ? cout << "Given string is permutation " : cout << "Given string is not permutation" ; 


    
    
    cout << endl;
    return 0;
}