/*  
 i/ p  = "205"    o/p = "205"
 i/ p  = "504"    o/p = "5"

 we have to return largest odd no as substring or comlete string 

 so we started to check from right to left (opposite loop)

 and if it is odd then return becuase it will maxiumum bcz we are checking from right to left

 so return that substring from 0 index to i index , so starting index is 0 and size is  i + 1 (initial i is 0)

 */

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<stack>


using namespace std;




string largest_odd_nos_string(string str){
    for (int i = str.size() -1 ; i >= 0 ; i--){
        if ((str[i] - '0')& 1)
            return str.substr(0,i+1);
    }
    return " ";
}

 int main(){

    cout << endl ;

    string str = "504" ; 
    cout << largest_odd_nos_string(str); 

    return 0;
}

 