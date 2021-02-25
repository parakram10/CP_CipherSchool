#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if (!n || !m)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}


int main(){
    int n, m;
    
    string s1 = "HelloWorld";
    string s2 = "HiandHelloWorld";
    cout << longestCommonSubsequence(s1, s2);
 
    return 0;
}