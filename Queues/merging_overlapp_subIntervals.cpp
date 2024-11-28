#include <bits/stdc++.h>
using namespace std;

/* 
MERGING OVERLAPPING SUBINTERVALS

    i/p : {{1,3},{2,4},{6,8},{9,10}}
    o/p : {{1, 4}, {6, 8}, {9, 10}}

    Method 1: By sorting
        TC = O(N*log(N))
        SC = O(1)



    Method 2: By using stack
        // logic is same so TC same and SC increase.
        for each interval
            doesnt overlap with stack top , push it 
            if current interval with top & ending is more than stack top update top 

        // in this all come in reverse order as it is stack but answer is correct  (reversely ordered)
        

 */
struct Interval{
    int s, e;
};
bool my_comp(Interval a , Interval b ){return a.s < b.s;}

void solve1(vector<Interval> &ip){
    sort(ip.begin(), ip.end(), my_comp);
    int index = 0;
    for (int i = 1; i < ip.size(); i++){
        if (ip[index].e >= ip[i].s) ip[index].e = max(ip[index].e, ip[i].e);
        else {
            index++;
            ip[index] = ip[i];} 
    }
    ip.resize(index+1); // resizing the size of array
}




void solve2(vector<Interval> &ip){
    stack<Interval> st;
    st.push(ip[0]);
    for (int i = 1; i < ip.size(); i++){
        if (st.top().e < ip[i].s) st.push(ip[i]);
        else st.top().e = max(st.top().e, ip[i].e);
    }
    ip.clear();
    while (!st.empty()){
        ip.push_back(st.top());
        st.pop();
    }
}

void printIntervals(const vector<Interval>& intervals) {
    for (const auto &interval : intervals) {
        cout << "[" << interval.s << ", " << interval.e << "] ";
    }
    cout << endl;
}

int main() {
    vector<Interval> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    cout << "Original Intervals: ";
    printIntervals(intervals);

    solve1(intervals);

    cout << "Merged Intervals: ";
    printIntervals(intervals);

    intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    solve2(intervals);
    cout << "Merged Intervals 2 : ";
    printIntervals(intervals);




    return 0;
}