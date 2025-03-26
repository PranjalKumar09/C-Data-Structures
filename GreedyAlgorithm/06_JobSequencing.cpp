#include <bits/stdc++.h>
using namespace std;

/* 
    Job Sequencing Problem
    Each job has:
    - id
    - deadline
    - profit
    Goal: Maximize total profit while respecting job deadlines.

    Here inner for loop (int j = deadline; j > 0; j--) can we optimized more by DSU (Disjoint Set Union) to O(1)
*/

vector<vector<int>> jobs = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};

// Custom comparator to sort jobs by profit (descending order)
bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] > b[2];  // Sort jobs by profit in descending order
}

pair<int, int> solve() {
    int n = jobs.size();

    // Step 1: Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), comparator);

    // Step 2: Find maximum deadline to create a job schedule array
    int maxDeadline = 0;
    for (auto &job : jobs) {
        maxDeadline = max(maxDeadline, job[1]);
    }

    // Step 3: Create a schedule array (size = maxDeadline) initialized with -1
    vector<int> schedule(maxDeadline + 1, -1);
    int totalProfit = 0, countJobs = 0;

    // Step 4: Try placing each job in its latest available slot
    for (auto &job : jobs) {
        int id = job[0], deadline = job[1], profit = job[2];

        // Find the latest available slot before or on the deadline
        for (int j = deadline; j > 0; j--) {
            if (schedule[j] == -1) {  // If slot is empty, assign the job
                schedule[j] = id;
                totalProfit += profit;
                countJobs++;
                break;  // Job placed, move to the next job
            }
        }
    }

    return {countJobs, totalProfit};  // Return total jobs done & max profit
}



/* 
// Custom comparator to sort jobs by profit (descending order)
bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] > b[2];  // Sort jobs by profit in descending order
}

// DSU Structure
vector<int> parent; 

// Find function with path compression
int find(int x) {
    if (parent[x] == x) return x;  // If x is its own parent, return x
    return parent[x] = find(parent[x]);  // Path compression
}

// Union function to merge sets
void unionSet(int u, int v) {
    parent[u] = v;  // Merge u into v (marking the next available slot)
}

pair<int, int> solve() {
    int n = jobs.size();

    // Step 1: Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), comparator);

    // Step 2: Find maximum deadline to initialize DSU
    int maxDeadline = 0;
    for (auto &job : jobs) {
        maxDeadline = max(maxDeadline, job[1]);
    }

    // Step 3: Initialize DSU parent array
    parent.resize(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++) {
        parent[i] = i;  // Each slot is initially its own parent
    }

    int totalProfit = 0, countJobs = 0;

    // Step 4: Place jobs using DSU for optimal scheduling
    for (auto &job : jobs) {
        int id = job[0], deadline = job[1], profit = job[2];

        // Find the nearest available slot using DSU
        int availableSlot = find(deadline);

        // If a valid slot is found
        if (availableSlot > 0) {
            totalProfit += profit;
            countJobs++;
            unionSet(availableSlot, availableSlot - 1);  // Mark this slot as taken
        }
    }

    return {countJobs, totalProfit};  // Return total jobs done & max profit
}

 */

int main() {
    pair<int, int> result = solve();
    cout << "Total Jobs Done: " << result.first << "\n";
    cout << "Maximum Profit: " << result.second << "\n";
    return 0;
}
