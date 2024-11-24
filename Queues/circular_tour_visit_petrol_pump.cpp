#include <bits/stdc++.h>
using namespace std;

/* 
    CIRCULAR TOUR THATS VISITS ALL PETROL PUMP

    starting point to complete circle without circle without exhausting petrol in b/w it is in circle 

i/p : (petrol , distance) = (4,6) , (6,5) , (7,3) , (4,5)
o/p : 1

    


    Method 1 : B.F. 
        TC = O(N^2)
        SC = O(1)

    Method 2 :  

            Set start = 0 & end = 1
            Iterate -> if petrol possible to reach nexgt end++
                    -> else start++
                    -> if start = N, not possible
                    else return start


    Method 3 : Optimized

 */

struct petrol_Pump{
int distance , petrol;
};

/* int solve(vector<petrol_Pump> &ip) {
    int n = ip.size();
    int start = 0;
    int end = 1;
    int curr_petrol = ip[start].petrol - ip[start].distance;
    
    cout << "Initial curr_petrol: " << curr_petrol << endl;
    while (start != end || curr_petrol < 0) {
        while (curr_petrol < 0 && start != end) {
            cout << "curr_petrol before adjusting start: " << curr_petrol << endl;
            cout << "Subtracting pump " << start << ": petrol = " << ip[start].petrol << ", distance = " << ip[start].distance << endl;
            
            curr_petrol -= ip[start].petrol - ip[start].distance;
            start = (start + 1) % n;
            
            cout << "New start: " << start << ", curr_petrol after adjusting start: " << curr_petrol << endl;
            if (start == 0) return -1;
        }
        
        cout << "curr_petrol before adjusting end: " << curr_petrol << endl;
        cout << "Adding pump " << end << ": petrol = " << ip[end].petrol << ", distance = " << ip[end].distance << endl;
        
        curr_petrol += ip[end].petrol - ip[end].distance;
        end = (end + 1) % n;
        
        cout << "New end: " << end << ", curr_petrol after adjusting end: " << curr_petrol << endl;
    }
    
    return start;
}

 */

int solve2(vector<petrol_Pump> &ip ){
    int n = ip.size();
    int start = 0;
    int end = 1;
    int curr_petrol = ip[start].petrol - ip[start].distance;
    while(start!= end || curr_petrol < 0){
        while(curr_petrol < 0 && start!= end){
            curr_petrol -= ip[start].petrol - ip[start].distance;
            start = (start + 1  ) % n;
            
            if(start == 0) return -1;   
        }
        curr_petrol += ip[end].petrol - ip[end].distance;
        end = (end + 1) % n;
    }
    return start;
}


int solve3(vector<petrol_Pump> &ip){
    int deficit = 0 , balance = 0, start = 0 ;
    for (int i = 0 ; i < ip.size(); i++){
        balance+= ip[i].petrol - ip[i].distance;
        if (balance < 0){
            deficit += balance;
            start = i + 1;
            balance = 0;
        }}
    if (deficit + balance >= 0)    return start;
    return  -1;}


int main() {
    // Define some sample petrol pumps
    vector<petrol_Pump> petrolPumps = { // twisted
        {6, 4},
        {5, 6},
        {3, 7},
        {5, 4}
    };

    // Call the solve function
    int start = solve3(petrolPumps);

    // Output the result
   
        cout << "Start at petrol pump: " << start << "\n";
    

    return 0;
}

