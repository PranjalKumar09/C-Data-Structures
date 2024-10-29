#include <bits/stdc++.h>
using namespace std;

// Replace file

int main(){
    ifstream input("old_file.txt");
    string oldStr = "pp";
    string newStr = "++";
    ofstream ouput("old_file2.txt");

    if (input.is_open()){
        string line;
        while(getline(input, line)){
            if (line.find(oldStr)!= std::string::npos)
                line.replace(line.find(oldStr), oldStr.length(), newStr);
            
            ouput << line << endl;
            
        }
       
    }
    else cout << "Unable to open file"; 
    
    input.close();
    
    return 0;


    
}