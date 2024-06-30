/* in insetion sort select element and place it correct position creating sorted from previous one 
when all element of arr are identicak least timen by insertion sort

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int> &arr){
    cout << endl << "{ ";
    int size = arr.size();
    for (int i = 0 ; i < size - 1 ; i ++)
        cout <<  arr[i] << " , ";
    cout << arr[size-1] << " }";
}

void Insertion_Sort(vector<int> &Array){
    for(int i  = 0 ; i < Array.size() ; i++){
        int j = i ;
        while ( j > 0 && Array[j-1] > Array[j]){   
        swap(Array[j-1], Array[j]); j = j-1; //  swap(Array[j-1], Array[j--]); <-his will not work well
}    }}


int main(){
    cout << endl;
    
    vector<int>  array = {1,2,3,2,1};
    display(array);
    Insertion_Sort(array);
    display(array);
    cout << endl;
    return 0;
}
