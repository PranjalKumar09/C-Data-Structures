#include <bits/stdc++.h>

using namespace std;

/* 
REMOVED K DIGITS

TC = O(N)
SC = O(N)

GIVEN : non zero in i/p
        removed k digit that such no become lowest



k=2 ip = 372181  
||                  *    ||
||                       ||
||                       ||
||      *                ||
||                       ||
||                       ||
||                       ||
||  *                    ||
||          *            ||
||              *       *||
===========================
    3   7   2   1  8   1
===========================
        7 - 2  first slide

||              *    ||
||                   ||
||                   ||
||                   ||
||                   ||
||                   ||
||                   ||
||  *                ||
||      *            ||
||          *       *||
=======================
    3   2   1  8   1
=======================

||          *    ||
||               ||
||               ||
||               ||
||               ||
||               ||
||               ||
||               ||
||  *            ||
||      *       *||
===================
    2   1  8   1
===================
   3 - 2  first slide


This works even with zeros


 */

string removeKdigits(string num, int k) {
    stack<char> s;
    for (char c : num) {
        while (!s.empty() && k > 0 && s.top() > c) {
            s.pop();
            k--;
        }
        if (!s.empty() || c != '0')   // Avoid leading zeros
            s.push(c);
        
    }
    
    // If there are still digits to remove, remove them from the end
    while (!s.empty() && k > 0) {
        s.pop();
        k--;
    }
    
    // Build the resulting number from the stack
    string result;
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    // Reverse the result since we constructed it from the stack
    reverse(result.begin(), result.end());
    
    // If the result is empty, return "0"
    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;
    cout << "Result: " << removeKdigits(num, k) << endl;
    return 0;
}