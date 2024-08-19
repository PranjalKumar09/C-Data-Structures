/*  
map mehtod -> TC => O(N2) 
SC => O(N)


vector <pai ..  method 
also note that 'z' + 1 => 123 it doesnt give error
TC => (122 log 233 + len ( string ))



 */

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<stack>


using namespace std;


template <typename T1, typename T2>
struct by_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};



string sort_sting_according_to_frequency(string str){
    map<char,int> frequency_count ;
    for (char ch : str) frequency_count[ch]++;
    vector<pair<char, int> > mapcopy(frequency_count.begin(), frequency_count.end());
    sort(mapcopy.begin(), mapcopy.end(), by_second<char, int>());
    str = "";
    for (auto i : mapcopy){
        while(i.second) {str += i.first;
        i.second--;}
    }
    return str;
}

string sort_sting_according_to_frequency_vector(string str){
    vector<pair<int , char > > hash ('z' + 1 , {0,0}) ; 
    // z => 122
    for (char c : str)
        hash[c] = {hash[c].first + 1, c}; // intial .first is => by this icrease +1 from first , 
    sort(hash.begin() , hash.end());
    string res = "";
    for (auto p : hash){
        // cout << string(p.first , p.end) ; 
        res = string(p.first , p.second) + res ; }
    return  res;
}
 int main(){

    string  str1 = "abbcded" , str2 = "dcchefe" ;
    cout << sort_sting_according_to_frequency_vector(str1) << endl;
    return 0;}




