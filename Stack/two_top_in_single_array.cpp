#include <iostream>
using namespace std;

class TwoStack{
    // Space not utilized if we take fixed size of stacks like n/2 & n/2 , Here we taken flexible that is good 
    int *arr;
    int top1 , top2 , size;

    public:

    TwoStack(int size) : size(size) ,top1(-1) ,top2(size) , arr (new int[size]) {} 

    void push1(int num){
        if (top2-top1 > 1) {
            top1++;
            arr[top1]=num;
        }
        else cout << "Stack overflow" << endl;
    }
    void push2(int num){
        if (top2-top1 > 1) {
            top2--;
            arr[top2]=num;
        }
        else cout << "Stack overflow" << endl;
    }
    int pop1(){
        if (top1>=0){
            top1--; 
            return arr[top1];
        }
        return -1;
    }
    int pop2(){
        if (top2<size){
            top2++; 
            return arr[top2];
        }
        return -1;
    }



    void print(){
        for (int i = max(0,top1); i<min(top2, size-1); i++)
                cout << arr[i] << " ";
                }
                
                };

int main(){
    TwoStack s(15);
    s.print();
}