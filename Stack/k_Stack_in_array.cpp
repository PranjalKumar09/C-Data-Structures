#include <iostream>
#include <stack>
#include <queue>


using namespace std;
/* 
K STACK IN AN ARRAY IMPLEMENTATION

                                        k1|k2|k3| -------------k(k-1)|kk|
                                       ___|__|__|__|__|__|__|__|__|__|__|
Method 1: Devide n length in K parts   |  |  |  |  |  |  |  |  |  |  |  |
                                       ----------------------------------
                            size->     n/k n/k

    * Space not optimized

Method 2:  
    top[] -> to represent top element indexes of size k
             intiliazed by -1

    next[] -> of size n & stores indexes for next element in array[0] 
    * point next element after stack top if element exist 

    TC = O(1)
    SC = O(2nK)
                                    
 */ 

class kStacks{
    int *arr , *top , *next , n , k , free ; //  free to store begining of indexes of free lists

public:

    kStacks(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for (int i = 0 ; i < n ; i++) top[i] = -1;
        free = 0;
        for (int i = 0 ; i < n-1 ; i++) next[i] = i + 1;
        next[n-1] = -1;
    }


    void push(int item , int sn){ //sn = stack no 
        if (sn > k-1) {
            cout << "Invalid Stack Number" << endl;
            return;
        }
        if (isFull()){
            cout << "Stack Overflow" << endl;
            return;}
        // *************************
        int i = free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;
        // *************************
        arr[i] = item;
    }

    int pop(int sn){
        if (isEmpty(sn)) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        // ************************* just opposite of push
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;
        // *************************
        return arr[i];
    }
    bool isFull(){
        return free == -1;
    }
    bool isEmpty(int sn){
        return top[sn] == -1;
    }


};



int main() {
    int n = 10; // Total size of the array
    int k = 3;  // Number of stacks
    kStacks stacks(n, k);

    // Push some elements to stack 0
    stacks.push(1, 0);
    stacks.push(2, 0);
    stacks.push(3, 0);

    // Push some elements to stack 1
    stacks.push(4, 1);
    stacks.push(5, 1);

    // Push some elements to stack 2
    stacks.push(6, 2);
    stacks.push(7, 2);
    stacks.push(8, 2);

    // Pop from stacks
    cout << stacks.pop(0) << endl; // Pop from stack 0
    cout << stacks.pop(1) << endl; // Pop from stack 1
    cout << stacks.pop(2) << endl; // Pop from stack 2

    return 0;
}