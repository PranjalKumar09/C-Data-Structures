#include <bits/stdc++.h>
using namespace std;

/*
    Alien Directory
    =====================


    i/p: No of string, strings
        K -> No of alphabet


    baa
    abcd
    abca
    cab
    cad

    o/p: alien order
    
    TC: O(N*M)      -> Topological sort
    SC: O(2K)+O(2K) -> Distance or array


*/


\

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1}};

    pair<int, int> source = {0, 0};
    pair<int, int> destination = {4, 4};

    int result = solve2(source, destination, grid);

    if (result != -1)
        cout << "The shortest path is: " << result << endl;

    else
        cout << "Path not possible" << endl;

    return 0;
}
