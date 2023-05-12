/*Ques: Implement a recursive algorithm for computing the greatest common divisor of two
integers using divide-and-conquer.*/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int a = 42;
    int b = 30;
    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is " << result << endl;
    return 0;
}
