#include <iostream>
#include <vector>
using namespace std;



int maximumProfit(vector<int>& price) {
   
    int profit = 0;

    for (int i = 1; i < price.size(); i++) {
        if (price[i] > price[i - 1]) {
            profit += price[i] - price[i - 1];
        }
    }

    return profit;
}

int main(){
    

    return 0;
}