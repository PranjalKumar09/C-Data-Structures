#include <iostream>
#include <cctype>
using namespace std;



int atoi( char* str, int& num) {
    // Base case: reached the end of the string or the current character is not a digit
    if (!str || !isdigit(str[0])) {
        return num;
    }

    num = (num * 10) + (str[0] - '0');

    return atoi(str + 1, num);
}

int main() {
    char* str = "12345";
    int result = 0;
    result = atoi(str, result);
    cout << "Converted integer: " << result << endl;

    return 0;
}