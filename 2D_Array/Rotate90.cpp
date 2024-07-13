/*

vector<vector < int > > temp (arr[0].size() , vector<int> ( arr.size()));
this sets all its element array to size of  arr.size() and its own size is arr[0].size()

in storing technique it can accept same and different  no of rows and column both But 
in same array it only accepts square matrix not other

Right -> ans array size  => [arr[0].size() , arr,size()] (in temp array)
Left -> ans arrar size => [arr.size() , arr[0].size()] (in temp array)

Right ->  temp[i][j] = arr[arr.size() - 1 - j][i];
Left ->  temp[i][j] = arr[j][arr[0].size() - 1 - i];

Right ->  swap(arr[i][start++], arr[i][end--]);  
Left ->   swap(arr[start++][i], arr[end--][i])








 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void display(vector<vector<int>> &arr){
    cout << "{ ";
    for (int j = 0; j < arr.size();j++){
        cout  << " { ";
        int size = arr[0].size();
        for (int i = 0 ; i < size - 1 ; i ++)
            cout <<  arr[j][i] << " , ";
        cout << arr[j][size-1] << " } ";
        if (j!= arr.size() - 1) cout << endl; 
    }
    cout << " }" << endl;
}

 vector<vector<int> > Rotate_90_by_storing_temp( vector<vector<int> > &arr){
    vector<vector < int > > temp (arr[0].size() , vector<int>(arr.size()));
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) 
            temp[i][j] = arr[arr.size() - 1 - j][i]; // right rotate
            // temp[i][j] = arr[j][arr[0].size()-1-i]; // left rotate
    }
    return temp;
 }
 vector<vector<int> > Rotate_90_in_same_array( vector<vector<int> > &arr){
    // Note this method workk only if no of rows and columns are equal
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i  + 1; j < arr[0].size(); j++) 
        swap(arr[i][j] , arr[j][i]);
        }
    for (int i = 0; i < arr.size(); i++) {  
        int start = 0 , end = arr.size() - 1;  
        while(start < end)  
            // swap(arr[i][start++], arr[i][end--]);    // to roatate right 
            swap(arr[start++][i], arr[end--][i]);  // TO ROTATE LEFT
    }
    return arr;

 }

// vector<vector<int> > Rotate90(vector<vector<int> >& array ){
    

int main(){
    cout << endl;
    
     vector<vector<int> > arr = { { 1, 2,  4 },
                              { 5, 6, 7 },
                              { 9, 11, 12 } };
    display(arr);

    cout << endl;
    cout << endl;

    // vector<vector<int> > ans = Rotate_90_by_storing_temp(arr);
    vector<vector<int> > ans = Rotate_90_in_same_array(arr);

    display(ans);




    cout << endl;
    return 0;
}

