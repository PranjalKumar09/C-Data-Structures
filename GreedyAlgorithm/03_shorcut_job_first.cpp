#include <bits/stdc++.h>
using namespace std;


/* 
    Shortest Job First

    Scheduling policy that select waiting process with smallest execution tim e to execute next
    

    Algo
        First sort it



 */

vector<int> arr = {3, 1, 4, 2, 5};


int solve(){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int time = 0, waitingTime = 0;


    for (int i = 0 ; i < n; i++){
        waitingTime += time;
        time += arr[i];
    }

    return waitingTime/n; // return average waiting time

}
int main() {
    
    cout << solve() << endl;    
    return 0;
}
