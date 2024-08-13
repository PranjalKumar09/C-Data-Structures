/*  
in brute force check ionly upto half not complete string
and start1 is fixed 0 while start depends on j of nested loop 

in brute force strat2  == str.length() because becase start2 will increased in prvious while 
similarly start1 taken not start + 1 because start2 value is inceased in while already


 */

#include <iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<stack>


using namespace std;

string brute_force_reverse_word_string(string str){
    stack <string> stck ;
    string temp = "", ans ="";
    for (int i = 0; i < str.length(); i++){
        if (str[i] == ' ') {
            stck.push(temp);
            temp = "";
        }
        else temp+=str[i];
    }
    stck.push(temp); // push last word

    while (!stck.empty()) {
        ans += stck.top() + " ";
        stck.pop();
    }
    ans.pop_back(); // Remove the extra space at the end
    return ans;

}


string optimized_reverse_word_string(string str){
   int left = 0 ,right = str.length() -1 ;
   string ans = "" , temp = "" ;
   while(left <= right){
    char ch = str[left];
    if (ch != ' ') temp += ch;
    else {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
        temp ="";
    }
    left++;
   }
   if (temp != ""){
    if (ans != "") ans = temp + " " + ans;
    else ans = temp;
   } 
    return ans;
}


 int main(){

    cout << endl ;

    string str = "Pranjal Kumar Shukla";
    cout << brute_force_reverse_word_string(str)  << endl << optimized_reverse_word_string(str) << endl ;

    return 0;
}

 