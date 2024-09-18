#include<iostream>
#include<vector>


using namespace std;

int brute_force(vector<int> &arr){
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
        int sum = 0;
            for (int k = i; k <= j; k++)sum  += arr[k] ; 
        maxi = max(maxi, sum);}}    
return maxi;}

int brute_force_2_nested(vector<int> &arr){
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++){
        int sum = 0;
        for ( int j = i; j < arr.size(); j++){
            sum += arr[j] ;
            maxi = max(maxi, sum);
        }
}
    return maxi;}



int optimized_solution(vector<int> &arr){
    int sum = 0, maxi = -1;
    for(int i = 0; i < arr.size(); i++)
    {sum += arr[i];
    if (sum > maxi) maxi = sum;
    if (sum<0)sum=0;}
    return maxi;}

int KadaneAlgorithm(vector<int> &arr){
    int sum = 0 , maxi = -1;
    for (int i = 0; i<arr.size() ; i++){
        if (sum < 0) sum = 0;
        sum += arr[i];
        if (sum > maxi) maxi = sum;} 
    return maxi;
}


int main(){
    cout << endl;
    
    vector<int> numbers = {-10, -5, 0, 2, 2, 2, 5, 8, 10, 15};
    cout << brute_force(numbers)<<endl;
    cout << brute_force_2_nested(numbers) <<endl;
    cout << KadaneAlgorithm(numbers)<< endl;
    cout << optimized_solution(numbers);
    cout << endl;
    return 0;
}