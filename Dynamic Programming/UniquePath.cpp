#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int uniquePaths(int m, int n)
{
    int dp[m+1][n+1];
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;
    if (a[m][n] != 0)
        return a[m][n];
    a[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    return a[m][n];
}

int main()
{
    int n = 4, m = 5;
    cout << uniquePaths(m, n);
}