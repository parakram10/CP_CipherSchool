#include <bits/stdc++.h>
using namespace std;

int minDistance(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

    return dp[m][n];
}

int main()
{
    string s1 = "SUNDAY";
    string s2 = "SATURDAY";
    cout << minDistance(s1, s2);
}