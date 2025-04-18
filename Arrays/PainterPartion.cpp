/* Given are N boards of with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of the board. The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


bool is_possiblle(vector<int> board , int time ,int no_of_painter_K){
    int sum = 0, painters = 1;
    for (int i = 0; i < board.size(); i++){
        if (board[i] + sum  <= time ) sum += board[i];
        else {
            painters++;
            
            if ( painters  >  no_of_painter_K ) return true;
            sum = board[i];
        }
    }
    return false;
}


int Painters_Partion(vector<int> board , int no_of_painter_K){
    // the answer will b/w range from maximum   to total sum of element (inclisive of both)
    int low = 0, high = 0, ans,sum = 0;
    for (int i = 0; i < board.size(); i++) {
        low = max(low, board[i]);
        high += board[i];
    }
    
    while ( low <= high ){
        int mid = low + (high - low)/2;
        cout << "Low: " << low << " high: " << high << " Mid "<< mid << endl;
        if ( is_possiblle(board , mid, no_of_painter_K)){
            ans = mid;
            low = mid + 1;        }
        else high = mid-1;}
        return low; //last low will always answer 
}

int main(){
    cout << endl;
    
    int  K = 3 ; 
    vector<int> A = { 10, 20,30, 40 } ; // We assuming that array will sorted
    sort( A.begin(), A.end());
    cout << Painters_Partion(A ,  K) << endl;
    
    cout << endl;
    return 0;
}