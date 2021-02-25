#include <bits/stdc++.h>
using namespace std;

int stair(int n)
{
    int dp[n + 1];
    for(int i=1;i<=n;i++)
    {
        if(i==1 || i==2)
        {
            dp[i]=i;
        }
        else
        {
            dp[i]=dp[i-1]+dp[i-2]; 
        }
        
    }
    return(dp[n]);
}

int main()
{
    int s = 10;
    cout << stair(s);
}