void Sprial_Print(vector<vector<int>> &arr){
    if (arr.size() < 1) return;
    int start_row = 0 , end_row = arr.size() - 1 , start_col = 0 , end_col = arr[0].size() - 1;
    while (start_col < end_col || start_row < end_row) {
        for (int i = start_col; i <= end_col; i++) 
            cout << arr[start_row][i]  <<  " " ;
        start_row++;
        for (int i = start_row; i <= end_row; i++)
            cout << arr[i][end_col] << " " ;
        end_col--;
        for (int i = end_col; i >= start_col ; i--)
            cout << arr[end_col][i] << " " ;
        end_row--;
        for (int i = end_row; i >= start_row ; i--)
            cout << arr[i][start_col] << " " ;
        start_col++;
    }
    

   
}