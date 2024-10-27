#include <bits/stdc++.h>
using namespace std;

// Count no of words

int main(){
    ifstream input("input5.txt");
    if (input.is_open()){
        string line;
        int count = 0;
        while(getline(input, line)){
            istringstream iss(line);
            string word;
            while(iss >> word){
                count++;
            }
        }
        cout << "Number of words: " << count << endl;
        input.close();
    }
    else cout << "Unable to open file"; 
    return 0;
    
}