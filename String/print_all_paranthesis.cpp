/* 
TC: O(2^n)
SC:  O(n)


 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;


void solution(int n1 , int n2, string str){
    if (n2 == 0 && n1 == 0 ) {
        cout << str << " " << endl;
        return;}
    if (n1 < 0 || n2 < 0 || n2 <  n1) return;
    solution(n1-1, n2, str+"{ " );
    solution(n1, n2 -1 , str+"} " );   

}



int main() {
    int n = 2; 
    solution(n, n, "");
    
    
    return 0;
}
