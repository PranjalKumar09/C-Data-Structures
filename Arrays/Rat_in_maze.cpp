/* 
TC=> O(4^(m*n)), because on every cell we need to try 4 different directions.

Space Complexity:  O(m*n)

of this function 

 */



#include<iostream>
#include<vector>

using namespace std;


void display (vector<string> &output){
    for (int i = 0 ; i < output.size() ; i++)
        cout << output[i] << "  ";}





void lenghty_relation(vector <vector<int> > & maze , int x, int y ,vector<vector<bool> > &vis  ,vector<string> &answer, string path ){
    if (y == maze.size() - 1 && x == maze[0].size() -1) {
        answer.push_back(path);
        return;
    }
  
    //Downward
    if (y+1 < maze.size()   && !vis[y+1][x] && maze[y+1][x] ) {
    vis[y][x] = 1;
    lenghty_relation(maze , x, y+1 ,vis , answer , path+'D' );
    vis[y][x] = 0;
}
    // right
   if (x+1 < maze[0].size()   && !vis[y][x+1] && maze[y][x+1] ) {
    vis[y][x] = 1;
    lenghty_relation(maze , x+1, y ,vis , answer , path+'R' ); // Corrected this line
    vis[y][x] = 0;
}
    //left
    if (x-1 >= 0   && !vis[y][x-1] && maze[y][x-1] ) {
    vis[y][x] = 1;
    lenghty_relation(maze , x-1, y ,vis , answer , path+'L' );
    vis[y][x] = 0;
}


    //upward
    if (y-1 >= 0    && !vis[y-1][x] && maze[y-1][x] ) {
    vis[y][x] = 1;
    lenghty_relation(maze , x, y-1 ,vis , answer , path+'U' );
    vis[y][x] = 0;
}
}
void small_solution(vector<vector<int>> &maze, int x, int y, vector<vector<bool>> &vis, vector<string> &answer, string path, vector<int> &x_axis, vector<int> &y_axis) {
    int n = maze.size();
    if (y == n - 1 && x == n - 1) {
        answer.push_back(path);
        return;
    }
    string code = "DRLU";
    for (int i = 0; i < 4; i++) {
        int nexti = x + x_axis[i];
        int nextj = y + y_axis[i];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nextj][nexti] && maze[nextj][nexti] == 1) {
            vis[nextj][nexti] = 1; 
            small_solution(maze, nexti, nextj, vis, answer, path + code[i], x_axis, y_axis);
            vis[nextj][nexti] = 0; 
        }
    }
}



int main(){


    
   vector<vector<int>> maze=   {{1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}}  ;
    vector<vector<bool>> vis(maze.size() , vector<bool>(maze[0].size() , false ) );
    vector<string> solution ; 


    // lenghty_relation(maze , 0 , 0, vis , solution , "");
    // display(solution);

    vector<int> x_varies = {0, 1, -1, 0};
    vector<int> y_varies = {1, 0, 0, -1};

    small_solution(maze, 0, 0, vis, solution, "", x_varies, y_varies);
    display(solution);


    

    return 0;
}


