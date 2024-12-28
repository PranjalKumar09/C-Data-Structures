#include <bits/stdc++.h>
using namespace std;

int getMinSwaps(vector<int> &original)
{
    int swaps = 0;
    vector<int> target = original;
    sort(target.begin(), target.end());

    // Map to track current positions of values
    unordered_map<int, int> pos;
    for (int i = 0; i < original.size(); i++)
    {
        pos[original[i]] = i;
    }

    // For each position, swap until correct value is placed
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] != target[i])
        {
            swaps++;

            // Update position of swapped values
            int curPos = pos[target[i]];
            pos[original[i]] = curPos;
            swap(original[curPos], original[i]);
        }
    }
    return swaps;
}

int main(){
    
}