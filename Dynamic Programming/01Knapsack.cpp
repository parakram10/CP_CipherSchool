#include<bits/stdc++.h>
using namespace std;


int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    int dp[n + 1][W + 1];
 
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1]+ dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
 
    return dp[n][W];
}


int main()
{
    vector<int> val = {40, 60, 100, 20, 50};
    vector<int> wt = {10, 20, 30, 40, 50 };
    int W = 120;
    cout<<knapSack(W, wt, val, val.size());
}