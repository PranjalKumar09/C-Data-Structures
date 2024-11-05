#include <bits/stdc++.h>
using namespace std;

/* 
Minimum Cost of Ropes
=====================
cost of connect 2 ropes equal to sum of their length. Task to connect ropes with minimum cost

i/p : {4 , 3 , 2 , 6}
    
      {4 , 5 , 6}

o/p : {9 , 6}

You have been given 'N' ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

The test-data is such that the result will fit into a 32-bit integer.
*/
int solve(vector<int> &arr){
    priority_queue<int, vector<int> , greater<int> > pq;
    for(int i = 0; i < arr.size(); i++)
        pq.push(arr[i]);
    int cost = 0;
    while(pq.size() != 1){
       int a = pq.top();
       pq.pop();
       int b = pq.top();
       pq.pop();
       cost += (a+b);
       pq.push(a+b);
    }
    return cost;
}

int main() {
    vector<int> arr = {4, 3, 2, 6}; // Sample input vector

    int minimum_cost = solve(arr); // Calculate the minimum cost using solve function

    cout << "Minimum Cost of Ropes: " << minimum_cost << endl; // Output the minimum cost

    return 0;
}

