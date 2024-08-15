/* 
i/p => {a , a,b,c,c,c,d,e,e}
o/p => {a , 2 , b , c , 3 , d,2}
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


template<typename T>
void display(vector<T> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

void string_compression(vector<char> &qns){
    int ansIndex =  0, i = 0;
    while(i < qns.size()){
        int j = i + 1;
        while(j < qns.size() && qns[j] == qns[i])
            j++;
        qns[ansIndex++] = qns[i]; // Store the character
        int count = j - i;
    if (count > 1){
        string temp = to_string(count);
            for (char ch: temp) // Store the count
                qns[ansIndex++] = ch;
    }    
    i = j;
}
    qns.erase(qns.begin() + ansIndex, qns.end());
    
}

int main(){
    cout << endl;

    vector<char> qns =  {'a', 'a', 'b', 'c', 'c', 'c', 'd', 'e', 'e'};
    string_compression(qns);
    display(qns);




    
    
    
    cout << endl;
    return 0;
}