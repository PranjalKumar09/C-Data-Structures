#include <bits/stdc++.h>
using namespace std;

/* 
INTERLEAVING TWO HALVES (OF QUEUE   )

i/p => 11 , 12 ,13 ,14, 15 ,16 , 17 ,18 , 19, 20
o/p => 11 , 16 ,12 ,17, 13 ,18 , 14 ,19 , 15, 20

    cycle of every loop ->half


 */

void print_Stack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void print_Queue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void solve(queue<int> &q){
    stack<int> s;
    int half_size = q.size()/2;
    for (int i = 0 ; i < half_size ; i++){
        s.push(q.front()); // push half element in stack 
        q.pop(); }
    cout << "Queue " ; print_Queue(q);// Queue 16 17 18 19 20 
    cout << "Stack " ; print_Stack(s); //Stack 15 14 13 12 11 

    while (!s.empty()){
        q.push(s.top()); // stack -> queue
        s.pop();}
    cout << "Queue " ; print_Queue(q); // Queue 16 17 18 19 20 15 14 13 12 11 
    cout << "Stack " ; print_Stack(s);


    for (int i = 0 ; i < half_size ; i++){ 
        q.push(q.front());  // first arrange heap of queue pop & push
        q.pop();}
    cout << "Queue " ; print_Queue(q);// Queue 15 14 13 12 11 16 17 18 19 20 
    cout << "Stack " ; print_Stack(s);


    for (int i = 0 ; i < half_size ; i++){ // first of queue to stack
        s.push(q.front()); 
        q.pop(); }
    cout << "Queue " ; print_Queue(q);// Queue 16 17 18 19 20 
    cout << "Stack " ; print_Stack(s);// Stack 11 12 13 14 15 



    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop(); }
    cout << "Queue " ; print_Queue(q);//Queue 11 16 12 17 13 18 14 19 15 20 
    cout << "Stack " ; print_Stack(s);
    }


int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    solve(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
