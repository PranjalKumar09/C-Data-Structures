#include <bits/stdc++.h>
using namespace std;

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    while (s.length() >=3 && s.substr(0, 3) == "WUB"){
        s.replace(0, 3 , "");
    }
    cout << s << endl;
    while (s.length() >=3 && s.substr(s.length()-3, 3) == "WUB"){
        s.replace(s.length()-3, 3, "");
    }
    int pos = 0;
    while (pos  = s.find("WUB", 0) != string::npos){
        s.replace(pos ,3, " ");
    }
    cout << s;

}