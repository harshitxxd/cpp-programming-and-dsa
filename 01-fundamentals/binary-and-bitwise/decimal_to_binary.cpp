/*
 * File: decimal_to_binary.cpp
 * Description: This program converts a decimal number into its binary representation.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
int dectobin() {
    int decno, rem, ans = 0, pow = 1;
    cout << "enter the decimal value";
    cin >> decno;

    while (decno > 0) {
        rem = decno % 2;
        decno = decno / 2;
        ans += (rem * pow);
        pow *= 10;
    }

    cout << "binary value is " << ans;
    return ans;
}

int main() {
    dectobin();
    return 0;
}
