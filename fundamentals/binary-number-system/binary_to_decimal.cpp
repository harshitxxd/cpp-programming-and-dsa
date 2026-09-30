/*
 * File: binary_to_decimal.cpp
 * Description: This program converts a binary number into its decimal equivalent.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
int bintodec() {
    int binno, rem, ans = 0, pow = 1;
    cout << "enter the binary value";
    cin >> binno;

    while (binno > 0) {
        rem = binno % 10;
        binno = binno / 10;
        ans += (rem * pow);
        pow *= 2;
    }

    cout << "decimal value is " << ans;
    return ans;
}

int main() {
    bintodec();
    return 0;
}
