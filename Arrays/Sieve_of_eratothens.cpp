/* TC => O(N/2 + N/3 + N/5 +  N/7 ... ) => TC => O(N * log(NlogN))
SC => O(N+1)


 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Sieve_of_eratothens(int num){
    vector <bool> checkers(num+1 , true) ; 
    checkers[0] =  checkers[1] = false ;
    for (int i = 0 ; i * i <=  num; i++){
        if ( !checkers[i] ) continue;
        checkers[i] = true ;
        for (int j =  i*i ; j <= num; j+=i)
            checkers[j] = false ;
}
    for (int i = 0 ; i <= num; i++)
        {if (checkers[i] == true)
            cout << i << " ";
    }
}

int main(){
    cout << endl;

    int num = 88;
    Sieve_of_eratothens(num);

    cout << endl;
    return 0;
}

