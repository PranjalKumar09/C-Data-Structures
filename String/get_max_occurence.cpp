/* first for loop fill all data in answer and second one find max 

correct  arr[str[i]-'a'] +=1;  
not correct arr[i-'A'] +=1 
*/

#include <iostream>

using namespace std;

char get_max_occurance(string &str){
    int arr[26] = {0};
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'a' && str[i] <= 'z')  arr[str[i]-'a'] ++;  // for lower case
        else if (str[i] >= 'A' && str[i] <= 'Z')  arr[str[i]-'A']++; // for upper case
    }

    int max = arr[0];
    char ans = 'a';
    for (int i = 0; i < 26; i++){
        if (arr[i] > max){

            max = arr[i];
            ans = i+'a';
        }
    }
    return ans;

}

int main(){
    cout << endl;

    string str;
    cout << " Enter a string: ";
    getline(cin, str); cout << endl;
    cout << " The maximum occurance is: " << get_max_occurance(str) ;







    cout << endl;
    return 0;
}