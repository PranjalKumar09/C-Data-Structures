

Minimum Cost to make array Equal (L-2448)


   
ll getCost(vector<int>& nums, vector<int>& cost, int target) {
    ll result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        result += (ll) abs(nums[i] - target) * cost[i];
    }
    return result;
}

long long minCost(vector<int>& nums, vector<int>& cost) {
    
    ll answer = INT_MAX;
    
    int left = *min_element(nums.begin(), nums.end());  //1
    int right = *max_element(nums.begin(), nums.end()); //5
    
    while (left <= right) {
        int mid = left + (right-left)/2;
        
        ll cost1 = getCost(nums, cost, mid);
        ll cost2 = getCost(nums, cost, mid + 1);
        
        answer = min(cost1, cost2);
        if (cost1 > cost2)
            left = mid + 1;
        else
            right = mid-1;
    }
    return answer == INT_MAX ? 0 : answer;



1970. Last Day Where You Can Still Cross
    class Solution {
public:
    ...
    bool solve(vector<vector<int>>& cells, int mid){
        vector<vector<int>> grid(ROW, vector<int>(COL,0));
        for (int i = 0; i <= mid; i++){
            int x=  cells[i][0]-1, y=  cells[i][1]-1;

            grid[x][y] = 1; 
        }

        for (int i = 0; i < COL; i++){
            if (grid[0][i] == 0 && DFS(grid,0, i)) return 1;
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row, COL = col;
        int l = 0, r = cells.size() - 1;

        int ans = 0;

        while(l <= r){
            int mid = l+(r-l)/2;
            if (solve(cells, mid)){
                ans = mid+1;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;


    }
};



Peak index in mountain array
    while(l < r){
        if (arr[mid] < arr[mid + 1]) l = mid+1;
        r  = mid;
    }

    

1870. Minimum Speed to Arrive on Time
    In this question condition is interesting


Maximum Running Time of N Computers | L-2141
    One of good question


Minimize the Maximum Difference of Pairs | L-2616
    Sort the array
    Check this question too





* Generally we do , when left we select and condition as l<r-> mid = l+ (r-l+1)/2;



median of 2 array
    m + n size
    sort both

    starting , l = 0, r= n (not n-1)

    left side more or equal => (m+n+1)/2
    right side => n 

    we have to make valid partition

    we can take first array small so it TC is small

    a1 a2 | a3
    b1 b2 | b3 b4


    ---- x1 | x2 ---
    ---- x3 | x4 ----
    even -> (max(x1, x3) + min(x2,x4))/2
    odd -> max(x1, x3)


    if (x1 > x4) h = mid-1;
    else l = mid+1;




    such that a2 <= b3
    and b2 <= a3

    a1 a2 a3 |
    b1       | b2 b3 b4




Searching smallest target index in mountain array (L1095)
    1) Find Peak Index
    2) 0 to idx
    3) idx+1 to n-1


Apply Operations to Maximize Frequency Score | L2968

    Ans must be in array
    l = min(array), h = max(array)

    sort (array)
    then we will do operation those just adjacents one


Find the Safest Path in a Grid | L2812
    This question is good bcz we have to do multi source bfs as pre compute

    and for minimum we do it, after this it become easy
     

queue<pair<int, int>> q;
vector<vector<int>> dis(n, vector<int>(n, -1));
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (grid[i][j] == 1) {
            q.push({i, j});
            dis[i][j] = 0;
        }

while (!q.empty()) {
    auto [i, j] = q.front(); // DIFF 6: Structured binding for clarity (original used q.front().first/second)
    q.pop();
    for (int d = 1; d < 5; d++) {
        int new_i = i + dir[d-1], new_j = j + dir[d];
        if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < n && dis[new_i][new_j] == -1) {
            dis[new_i][new_j] = dis[i][j] + 1; // Same as original
            q.push({new_i, new_j});
        }
    }
    // DIFF 7: Removed level-based BFS (original used size loop, unnecessary for Manhattan distances)
}
