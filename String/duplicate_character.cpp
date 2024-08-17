#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

void print_all_duplicates_by_hashiing(string str){
    map <char, int> frequency_count;
    for (int i = 0; i < str.size(); i++) 
        frequency_count[str[i]]++;
    for (auto i : frequency_count)
        if (i.second > 1) cout << i.first << " ";
    cout << endl;
}

void print_all_duplicates_by_brute_force(string str){
    set<int> st;
    for (int i = 0; i < str.size(); i++){
        for (int j = i+1 ; j < str.size() ; j++){
            if (str[i] == str[j]){
                st.insert(i);
                break;
            }
        }
    }
    for (auto i : st) {
        cout << str[i] << " ";
    }
}

void print_all_duplicates_by_optimiazed(string str){
    sort(str.begin() , str.end()) ; 
    for (int i   = 0 ; i < str.size() - 1 ; i++ ) {
        int count = 1;
        while( (i < str.size() - 2 && str[i] == str[i+1])){
            count++;
            i++;
        }
        if (count > 1) cout << " " << str[i] ;

    }


}


int main(){
    cout << endl;

    string word = "Hello hai world!";
    print_all_duplicates_by_brute_force(word);
    print_all_duplicates_by_hashiing(word);
    print_all_duplicates_by_optimiazed(word);

    cout << endl;
    return 0;
}