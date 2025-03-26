#include <bits/stdc++.h>

using namespace std;


/* 
    Fractional Knapsack

    Question asked total double we get , however we can we can also select which item


    Greedy Algorithm
    ----------------
    ----------------

    sort(arr, comparator(value by weight))

    double totalValue = 0;

    for (i -> n)
        if (arr[i] - weight <= W){
            totalVal += arr[i] - value;
            W = W - arr[i];
        }
        else   {totalVal += ( arr[i]-value) / (arr[i]-weight) * weight
            break;}
    return totalValue;


*/


struct Item {
    double weight, value;
};

bool comparator(Item &a, Item &b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(vector<Item> &items, double W) {
    sort(items.begin(), items.end(), comparator);  // Step 1: Sort by value/weight

    double totalValue = 0.0;

    for (auto &item : items) {
        if (W >= item.weight) {  // Take full item
            totalValue += item.value;
            W -= item.weight;
        } else {  // Take fractional part
            totalValue += (item.value / item.weight) * W;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    double W = 50;

    cout << "Maximum Value: " << fractionalKnapsack(items, W) << endl;
    return 0;// also guide me related
}
//