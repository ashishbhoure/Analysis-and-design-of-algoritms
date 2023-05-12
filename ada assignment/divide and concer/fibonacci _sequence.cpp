/*Ques: Implement a recursive algorithm for computing the Fibonacci sequence using
divide-and-conquer.*/

#include <iostream>

using namespace std;

void fibonacci(int n, int& prev, int& curr) {
    if (n == 0) {
        prev = 0;
        curr = 1;
    } else {
        int prevPrev, prevCurr;
        fibonacci(n / 2, prevPrev, prevCurr);
        prev = prevPrev * (2 * prevCurr - prevPrev);
        curr = prevCurr * prevCurr + prevPrev * prevPrev;
        if (n % 2 == 1) {
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
    }
}

int main() {
    int n = 6;
    int prev, curr;
    fibonacci(n, prev, curr);
    cout << "Fibonacci sequence up to " << n << ":" << endl;
    for (int i = 0; i <= n; i++) {
        cout << prev << " ";
        int temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    cout << endl;
    return 0;
}
