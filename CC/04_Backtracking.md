
Word Search L79

class Solution {
    int dir[5] = {0,-1,0,1,0};
    int m, n;
public:
    bool find(vector<vector<char>>& board,int i, int j, int idx, string word){
        if (idx == word.length()) return 1;
        if (0 > i || m -1 < i || 0 > j || n -1 < j || word[idx] != board[i][j]) return 0;
        char ch = board[i][j];
       board[i][j] = '*';

       for (int k = 1; k < 5; k++)
        if (find (board, i+dir[k-1], j+dir[k], idx+1,word)) return true;  
       board[i][j] = ch;

       return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0] && find(board, i, j, 0, word))   return 1;

        

        return 0;  
        
    }
};