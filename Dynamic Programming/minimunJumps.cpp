#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> v)
{
    int n = v.size();
    int dp[n];
    int i, j;

    if (n == 0 || v[0] == 0)
        return INT_MAX;

    dp[0] = 0;

    for (i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + v[j] && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    vector<int> v = {2,3,2,10,6,9};
    cout << minJumps(v);
}
