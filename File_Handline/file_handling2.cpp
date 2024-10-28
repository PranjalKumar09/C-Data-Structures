#include <bits/stdc++.h>
using namespace std;

/* 
    To check file can be opened if it conatins errors infile five true = >   if (!infile)
    
    To Edit data in file
    ---------------------
        1) Read upto previous line of edit text
        2) Copy all in new file & manipulate edited line
        3) You can overwrite it now in file
        4) Close file






 */

int main(){
    ifstream infile("input.txt");
    if (!infile)
        cout << "Error opening file!" << endl;
    


    // Creating & write some text file 
    ofstream f1("input.txt");
    if (f1.is_open()){
        f1 << "Sample data 1" ;
        f1 << "\nSample data 2" << endl << "Sample data 3" << endl;  
        f1.close(); 
    }
    else cout << "Unable to open file";

    // Reading file & printing each line
    ifstream f2("input.txt");
    string line;
    while (getline(f2, line))
        cout << line << '\n';
    

    // Now changing Sample data 3  to Sample data 4 
    string oldStr = "Sample data 3";
    string newStr = "Sample data 4";

    ofstream fw2("input2.txt"); // in new file 
   
    ifstream f3("input.txt");
    if (fw2.is_open()){
        while (getline(f3, line )){
            if (line.find(oldStr)!= std::string::npos)
                line.replace(line.find(oldStr), oldStr.length(), newStr);
            fw2 << line << '\n';
        }


    }
    else cout << "Unable to open file";

 
    fw2.close();
    f2.close();


    return 0; 
    
}