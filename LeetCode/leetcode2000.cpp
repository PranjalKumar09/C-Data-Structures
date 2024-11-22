#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) { 
        // not solve the case when ch not present in word 
        string reverse_part ;
        reverse_part = word[0];
        int i;
        for (i =1; i<word.length(); i++){
            if (ch == word[i-1]) break;
            reverse_part = word[i] + reverse_part;
        }
        for (int j = i; j < word.length(); j++)
            reverse_part += word[j];
        return reverse_part;
    }
};
class Solution { // recommeneded and best
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i<word.length(); i++) {
            if(word[i] == ch) {
                reverse(begin(word), begin(word)+i+1);
                break;
            }
        }
        return word;
    }
};

class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), begin(word) + word.find(ch) + 1);
        return word;
    }
};

int main(){
    string word = "abcdefd"; char ch = 'd';
    Solution s;
    cout << s.reversePrefix(word, ch) << endl;
}