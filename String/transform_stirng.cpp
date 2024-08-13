/* 
in this we have selected only those number which are prime inodd number and even in even number
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


void display(vector<string> lines){
    for(int i=0;i<lines.size();i++)
        cout<<lines[i]<<endl;
    
}


void solution(vector<string> &result ,vector<string> mapping  , string num , string output){

    if (num == "") { 
        result.push_back(output)    ; 
    return ; }
    
    int n = num[0] - '1'; // we are subtracting 1 bcz its 0 based indexing 
    
    for (int i = 0 ; i < mapping[n].length() ; i++){

        solution(result, mapping, num.substr(1), output + mapping[n][i]);
        // if we do push_back then we have to do pop but here no need we because we are doing from index 
    
}
    
}


    
    

int main(){
    vector<string> mapping  ={"","abc" , "def" ,"ghi" ,"jkl" ,"mno" ,"pqrs" ,"tuv" , "wxyz"  } ;
    vector<string> output;
    string num = "23";
    solution(output , mapping , num , "");
    display(output); 
    
    return 0;
}