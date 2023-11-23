#include <bits/stdc++.h>
using namespace std;

/*
    Minimum Multiplication to Reach End start end ,  it is multians % 10000
    arr = {..}

    You have to multiply element of arr to start to reach end

    End is not multi answer


    TC: O(100000 * N)
    SC: O(100000 * N)
*/
int solve(int start, int end, vector<int> &arr)
{
    queue<pair<int, int>> q; // Queue to store {current value, steps taken}
    q.push({start, 0});

    vector<int> dist(100000, 1e9); // Distance array initialized with a large value
    dist[start] = 0;

    while (!q.empty())
    {
        auto [current, steps] = q.front();
        q.pop();

        // If we have reached the end
        if (current == end)
        {
            return steps % 10000;
        }
        // /Optimization: Skip paths where current > end
        if (current > end)
        {
            continue;
        }

        // Try all possible multiplications
        for (int factor : arr)
        {
            int next = (current * factor) % 100000; // Keep within bounds
            if (dist[next] > steps + 1)
            {
                dist[next] = steps + 1;
                q.push({next, steps + 1});
            }
        }
    }

    return -1; // If it's not possible to reach the end
}

// Driver functionh
int main()
{
    int start = 2;               // Predefined start value
    int end = 40;                // Predefined end value
    vector<int> arr = {2, 3, 5}; // Predefined array of multipliers

    int result = solve(start, end, arr);
    if (result == -1)
    {
        cout << "Not possible to reach end from start.\n";
    }
    else
    {
        cout << "Minimum multiplications to reach end: " << result << "\n";
    }

    return 0;
}
