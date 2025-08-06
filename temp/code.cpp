#include <bits/stdc++.h>
using namespace std;

int main(){
    string str; cin >> str;
    int l = str.length(), c = 1;
    
    for (int i = 1; i < l; i++ ){
        if (str[i] == str[i-1]) c++;
        else c = 1;
        if (c==7){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

}