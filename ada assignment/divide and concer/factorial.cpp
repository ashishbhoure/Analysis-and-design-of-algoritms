/*Ques: Implement a recursive algorithm for computing the factorial of a given positive
integer using divide-and-conquer*/

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int half = n / 2;
        int result = factorial(half) * factorial(n - half);
        return n % 2 == 0 ? result : result * n;
    }
}

int main() {
    int n = 5;
    int fact = factorial(n);
    cout << "Factorial of " << n << " is " << fact << endl;
    return 0;
}
