#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;


// handles int range and better , it also handles sgin, intial gaps
int myAtoi(char *s)
{
    int i = 0;
    int n = strlen(s);
    long long no = 0; // Use long long to handle overflow during computation
    int positive = 1;

    // Skip leading spaces
    while (i < n && s[i] == ' ')
        i++;

    // Handle optional '+' or '-' sign
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            positive = -1;
        i++;
    }

    // Process numeric digits
    while (i < n && isdigit(s[i]))
    {
        no = no * 10 + (s[i] - '0');

        // Check for overflow
        if (positive == 1 && no > INT_MAX)
            return INT_MAX;
        if (positive == -1 && -no < INT_MIN)
            return INT_MIN;

        i++;
    }

    return (int)(no * positive);
}

int atoi( char* str, int& num) {
    // Base case: reached the end of the string or the current character is not a digit
    if (!str || !isdigit(str[0])) {
        return num;
    }

    num = (num * 10) + (str[0] - '0');

    return atoi(str + 1, num);
}

int main() {
    char* str = " 12345";
    int result = 0;
    result = atoi(str, result);
    cout << "Converted integer: " << result << endl;

    return 0;
}