#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string remove_duplicate(string str ){
    int arr[26] = {0};
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z')  str[i] = str[i] - 'A' + 'a';
        if (str[i] >= 'a' && str[i] <= 'z')  arr[str[i]-'a'] ++;  // for lower case
    }
    string ans = "";
    for (int i = 0; i <  str.length(); i++){
        if (arr[str[i]-'a' ]  != 0){
            arr[str[i]-'a'] = 0;
            ans.push_back(str[i]);
        }
    }
    return ans;
} 

int main(){
    cout << endl;

    string str = "HhelpHelp";
    string ans = remove_duplicate(str);
    cout << ans << endl;
    
    
    cout << endl;
    return 0;
}