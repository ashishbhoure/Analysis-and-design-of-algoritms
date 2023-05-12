/*Ques: Implement a divide-and-conquer algorithm for multiplying two large integers.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> multiply(vector<int>& x, vector<int>& y)
{
    int n = x.size();
    int m = y.size();
    vector<int> result(n + m, 0);

    if (n == 0 || m == 0)
        return result;

    if (n == 1 && m == 1)
    {
        result[0] = x[0] * y[0];
        return result;
    }

    int middle = n / 2;

    vector<int> xLeft(x.begin(), x.begin() + middle);
    vector<int> xRight(x.begin() + middle, x.end());

    vector<int> yLeft(y.begin(), y.begin() + min<int>(m, middle));
    vector<int> yRight(y.begin() + min<int>(m, middle), y.end());

    vector<int> P1 = multiply(xLeft, yLeft);
    vector<int> P2 = multiply(xRight, yRight);

    for (int i = 0; i < middle; i++)
        xRight[i] += xLeft[i];
    for (int i = 0; i < min<int>(m, middle); i++)
        yRight[i] += yLeft[i];

    vector<int> P3 = multiply(xRight, yRight);

    for (int i = 0; i < P1.size(); i++)
        result[i] += P1[i];

    for (int i = 0; i < P2.size(); i++)
        result[n + m - 1 - i] += P2[P2.size() - 1 - i];

    for (int i = 0; i < P3.size(); i++)
        result[middle + i] += P3[i] - P1[i] - P2[i];

    return result;
}

int main()
{
    string x_str = "3141592653589793238462643383279502884197169399375105820974944592";
    string y_str = "2718281828459045235360287471352662497757247093699959574966967627";

    vector<int> x(x_str.size());
    vector<int> y(y_str.size());

    for (int i = 0; i < x_str.size(); i++)
        x[i] = x_str[i] - '0';
    for (int i = 0; i < y_str.size(); i++)
        y[i] = y_str[i] - '0';

    vector<int> result = multiply(x, y);

    bool leading_zero = true;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != 0)
            leading_zero = false;
        if (!leading_zero)
            cout << result[i];
    }
    if (leading_zero)
        cout << "0";
    cout << endl;

    return 0;
}
