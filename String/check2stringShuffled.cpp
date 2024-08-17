/*  
Instead of counting frequqency in different map all do in one in same 

if( frequency_count.find(answer[k]) != frequency_count.end())

here in frequency_count we aare searching elemeents of found whether nsearch touched last or not

 */

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

bool check2string_shuffled_in_new(string s1, string s2, string answer){
    if (s1.size() + s2.size() != answer.size()) return false;
    map<char, int> frequency_count;
    for (int i = 0 ; i < s1.size() ; i++) frequency_count[s1[i]] ++;
    for (int j = 0 ; j < s2.size() ; j++) frequency_count[ s2[j]] ++;
    for (int k = 0 ; k < answer.size() ; k++) { if( frequency_count.find(answer[k]) != frequency_count.end()) frequency_count[answer[k]]--;
    else return false;}
    return true;
    
    }


int main(){
    cout << endl;

    string  str1 = "AXC", str2 = "ZYS", shuffle = "YBAZSC";
    cout << check2string_shuffled_in_new(str1, str2 , shuffle);

    cout << endl;
    return 0;
}