#include <bits/stdc++.h>
using namespace std;

/*  
Task Scheduler
==============
    cpu has cooldown 'k' for task, upto that task not take

    I/p :
     N = 6
     K = 2
     task = ['A' ,'A' ,'A' ,'B' ,'B' ,'B']
     
    O/p : A -> B -> idle -> A -> B -> idle -> A -> B 
        8 (minimum unit of time)
                      |
    k + 1  <= A ____ |A ____   
                k   |
    
    in every block can put one type of only one element
    max heap <int>
            (count)

            New
    A -> 5  4
    B -> 3
    C -> 3  3
    D -> 1

    {5, 4 --- }
    uptoSt = 0

*/
int solve(vector<char> &tasks, int k) {
    // Step 1: Count the frequency of each task
    unordered_map<char, int> counts;
    for (char task : tasks) 
        counts[task]++;

    // Step 2: Create a max heap to store task frequencies
    priority_queue<int> pq;
    for (auto &count : counts) 
        pq.push(count.second);

    int result = 0; // This will store the total time

    // Step 3: Process the tasks
    while (!pq.empty()) {
        int time = 0;
        vector<int> temp;

        // Step 4: Execute as many as k+1 tasks from the heap
        for (int i = 0; i <= k; i++) 
            if (!pq.empty()) {
                temp.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }
        

        // Step 5: Push remaining tasks back into the heap
        for (int remaining : temp) 
            if (remaining > 0) 
                pq.push(remaining);
        

        // Step 6: Calculate the time taken for this cycle
        result += pq.empty() ? time : k + 1;
    }

    return result;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int k = 2;
    int result = solve(tasks, k);
    cout << "Minimum intervals needed to execute all tasks: " << result << endl;
    return 0;
}


