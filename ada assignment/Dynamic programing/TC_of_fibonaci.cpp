/*Ques: Implement the Fibonacci sequence using dynamic programming in Cpp
Analyze the time complexity of your implementation and compare it with the time
complexity of a recursive implementation*/

#include <iostream>
using namespace std;

int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}


//Time complexity
/*This implementation has a time complexity of O(n), where n is the index of the Fibonacci number to be computed. This is because it computes each Fibonacci number only once and stores it in an array for later use.

In contrast, the recursive implementation of the Fibonacci sequence has a time complexity of O(2^n), where n is the index of the Fibonacci number to be computed. This is because it computes the same Fibonacci number multiple times, leading to a lot of redundant computation.*/