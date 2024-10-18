#include <bits/stdc++.h>
using namespace std;

/* 
Expression add operation
========================
    i/p : string , target
    o/p : string with operation to reach desired target

    i/p : num = "123", target = 6
    o/p : ["1*2*3","1+2+3"]

    i/p : string = 9 , target = 123
    o/p : 12-3 valid      (1+2)*3 Not valid



    TC: O(3^n)
    SC: O(n^3)
  
 */

void recursive(int i, string sumPath, long sum, long prev, string num, int target, vector<string>& result) {
    // i, sumpath f, sum for index ,taking path indexes and sum
    // prev just for multiplication purpose, num  and target are input given at starting , result we are storing all results
    if (i == num.size()) {
        if (sum == target) result.push_back(sumPath);
        return;
    }

    for (int j = i; j < num.size(); j++) {
        if (j > i && num[i] == '0') break;  // Skip leading zero numbers
        
        string tempStr = num.substr(i, j - i + 1);
        long number = stol(tempStr);

        if (i == 0) {
            recursive(j + 1, tempStr, number, number, num, target, result);  // First number, no operator
        } else {
            recursive(j + 1, sumPath + "+" + tempStr, sum + number, number, num, target, result);
            recursive(j + 1, sumPath + "-" + tempStr, sum - number, -number, num, target, result);
            recursive(j + 1, sumPath + "*" + tempStr, sum - prev + prev * number, prev * number, num, target, result); // according to bodmas multiplication exectues first so we removing the prev from sum then adding multipling
            // sum - prev + prev * number      most important thing
        }
    }
}

vector<string> solve(string num, int target) {
    vector<string> result;
    if (num.empty()) return result;
    recursive(0, "", 0, 0, num, target, result);
    return result;
}

int main() {
    string num = "33224";
    int target = 14;
    vector<string> result = solve(num, target);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}
