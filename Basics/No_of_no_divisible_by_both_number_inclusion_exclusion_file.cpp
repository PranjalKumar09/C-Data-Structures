/* 
we have to find total number divisble by num1 and num2 between ranges */





#include<iostream>


using namespace std;

int no_of_no_divisible_by_both_number_inclusion_exclusion_file(int num1 , int num2, int range_lower, int range_upper){
    /* int count = 0;
    for(int i = range_lower; i <= range_upper; i++)
        if(i % num1 == 0 || i % num2 == 0) count++;
    return count; */

    return abs((range_upper - range_lower + 1)/num1 )+ abs((range_upper - range_lower + 1)/num2) - abs((range_upper - range_lower + 1)/(num1*num2));
    }




int main(){
    cout << endl;

    int num1 = 5  , num2 = 7;
    int range_lower = 1 , range_upper = 500;
    cout << no_of_no_divisible_by_both_number_inclusion_exclusion_file(num1, num2, range_lower, range_upper);
    
    
    cout << endl;
    return 0;
}
