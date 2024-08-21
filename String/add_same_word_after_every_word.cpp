/* 

example :  Enter a string: my name is pranjal

 Enter a word: 123

The appended string is : my123name123is123pranja123

*/

#include <iostream>

using namespace std;

string append_word_in_this_string_in_every_word(string &str, string &word){
    string ans = "";
    for (int i = 0; i < str.length(); i++){
        if (str[i] == ' ' || i == str.length() - 1){
            for (int j = 0; j < word.length(); j++) ans.push_back(word[j]);
        }
        else    ans.push_back(str[i]);
        
    }
    return ans;

}

int main(){
    cout << endl;

    string str, word;
    cout << " Enter a string: ";
    getline(cin, str); cout << endl;

    cout << " Enter a word: ";
    cin >> word; cout << endl;
    
    cout << "The appended string is : " << append_word_in_this_string_in_every_word(str , word) ;







    cout << endl;
    return 0;
}