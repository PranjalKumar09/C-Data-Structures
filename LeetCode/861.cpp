        // 861. Score After Flipping Matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        // in this first one will always 1 so we going with that logic
       
        int M = grid.size(), N = grid[0].size(), res = (1 << (N - 1)) * M; //  (2^row )*column
        for (int j = 1; j < N; j++) {
            int cur = 0;
            for (int i = 0; i < M; i++) cur += grid[i][j] == grid[i][0];
            res += max(cur, M - cur) * (1 << (N - j - 1));
        }
        return res;
    
    }
};