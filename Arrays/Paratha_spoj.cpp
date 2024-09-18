#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is_possible(vector<int> &Ranks_of_cooks , int Chapatis , int total_time){
    int  chapati_count = 0;
    for (int i = 0; i <Ranks_of_cooks.size(); i++){
        int time = Ranks_of_cooks[i] , current_chief_rank = 2;
        while( time <= total_time){
            chapati_count++;
            time += Ranks_of_cooks[i]*current_chief_rank; 
            current_chief_rank++; 
        }
        if ( chapati_count >= Chapatis) return 1 ;
    }
    return 0 ;
}

int Paratha_SPOJ(vector<int> &Ranks_of_cooks , int Chapatis){

    int low = 0  , high = 1e8 ;  
    // int low = Chapatis , high = Ranks_of_cooks.size() * (Ranks_of_cooks.size() + 1)/2;
    while( low <= high ){
        cout << " low " << low << " high " << high << endl;
        int mid = low + (high - low) / 2;
        if (is_possible(Ranks_of_cooks , Chapatis, mid))high = mid-1;
        else low = mid+1;}
    return high+1;}

int main(){
    cout << endl;

    vector<int> Ranks_of_cooks = {1,2,3,4};
    int Chapatis = 10;
    
    cout << Paratha_SPOJ(Ranks_of_cooks, Chapatis);
    
    cout << endl;
    return 0;
}