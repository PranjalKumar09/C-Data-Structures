/* 

Probelm -> conatine only 1 & 0 and all rows are sorted 

Note in lower bound always add deducr with .begin() or .end() only


*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector <int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> optimize(vector<vector <int> > &arr){
    int maxi = -1, index= 0;    
    for (int i=0;i<arr.size();i++){
        int cnt_ones = arr[i].end() - lower_bound(arr[i].begin() , arr[i].end() , true );
        if (cnt_ones > maxi) { maxi = cnt_ones ; index = i;}
    }
    return arr[index];
}


vector<int> brute_force(vector<vector<int>> &arr){
    int maxi = -1, index= 0;
    for (int i = 0; i < arr.size(); i++) {
        int count =  0;
        for (int j = 0 ; j < arr[i].size() ; j++)
            if (arr[i][j]) count += 1 ;
        if (maxi < count) {maxi = count; index = i;}
    }
    return arr[index];

}

int main(){
    cout << endl;
    vector<vector<int>>  arr  = { {0, 0, 0, 1}, 
                    {0, 1, 1, 1}, 
                    {1, 1, 1, 1}, 
                    {0, 0, 0, 0}};
    vector<int> ans  =  brute_force(arr);
    display(ans);

    cout << endl;
    return 0;
}