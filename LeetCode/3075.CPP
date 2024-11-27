// Maximize Happiness of Selected Children
# include <iostream>
using namespace std;


class Solution {


public:
    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end());

        long long total = 0;
        int count = 0;
        for (int i =  happiness.size()  -1 ; count < k && i >= 0 ; i--){
            happiness[i] -= ( happiness.size() - 1 - i);

            if (happiness[i] <= 0 ) continue;

            total += happiness[i];
            count ++ ;

            }

        return total;
    }
};

int main(){


    
}
