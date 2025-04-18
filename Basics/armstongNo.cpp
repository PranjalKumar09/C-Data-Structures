#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrongNumber(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;

    // Count number of digits
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Edge case for 0
    if (num == 0) digits = 1;

    // Calculate the Armstrong sum
    temp = num;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    // Special case for 0 (since while loop is skipped)
    if (num == 0) sum = 0;

    return sum == original;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << endl;

    isArmstrongNumber(n)
        ? cout << "Number is an Armstrong number"
        : cout << "Number is not an Armstrong number";

    cout << endl;
    return 0;
}
