#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void display(vector<string> &sol ){
    sort(sol.begin() , sol.end());
    for (int i = 0 ; i < sol.size(); i++)
        cout << sol[i] << " ";
    cout << endl;
}

void approach1(string str ,string temp , vector<string> &sol , int index){
    if (index >= str.size()) {sol.push_back(temp); return ;}
    approach1(str , temp , sol, index+1);
    temp.push_back(str[index]);
    approach1(str,temp,sol, index+1);
    return ;
    }


void approach2(string str ,string temp , vector<string> &sol ){
    int n = str.length();   
    for (int num = 0 ; num < (1<<n) ; num++)  {//( 1 << n) = 2^n
        string sub = "";
        for (int i = 0 ; i<n;i++)
            if (num & (1<<i))
                sub += str[i];
        if (sub.length())  sol .push_back(sub);
        // num = 0 .. 2^n
    }
}
        
int main() {

    string str = "abc";
    vector<string> sol ;
    // approach1(str , "", sol , 0);
    approach2(str, "" , sol);
    display(sol);

    int x = 1<<9;
    cout << x ;





}