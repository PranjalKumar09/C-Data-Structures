#include <bits/stdc++.h>

using namespace std;

/*
    Candy Slope Approach
        * Each child should at least one candy
        * Children with higher rating should have candy more than neighbour
        * We have to give minimum candy needed to do this
    
        arr    = 1 3 2 1
    institution
        left   = 1 2 1 1
        right  = 1 3 2 1
        combine= 1 3 2 1
        ( should statsfying both neighbor)


    Candy Distribution (Greedy Slope Approach)
    - TC: O(N)
    - SC: O(N)
*/

vector<int> ratings = {1, 3, 2, 1};

int minCandies() {
    int n = ratings.size();
    vector<int> candies(n, 1);  // Step 1: Give each child 1 candy

    // Step 2: Left-to-right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Right-to-left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Step 4: Sum up the candies
    return accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    cout << "Minimum Candies Needed: " << minCandies() << endl;
    return 0;
}

