#include <bits/stdc++.h>
using namespace std;


/* 

    Lemonade Change
 */

vector<int> bills = {5, 5, 5, 10, 20};

bool solve() {
    int  n = bills.size();
    int five = 0, ten = 0;

    for (int i: bills){
        if (i == 5) five ++;
        else {
            if (i == 10 ){
                if (five)
                {ten++;
                five--;}
                else return false;
            }
            else {
                if (ten && five)
                {ten--;
                five--;}
                else if (five >= 3)
                {five -= 3;}
                else return false;
            }
        }
    }
    return true;
}

int main() {
    
    cout << solve() << endl;    
    return 0;
}
