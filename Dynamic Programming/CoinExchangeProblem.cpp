#include<bits/stdc++.h> 
using namespace std; 

int countCoins(vector<int> coins, int n ) 
{ 
    int m = coins.size();
	int dp[n + 1][m]; 
	for (int i = 0; i < m; i++) 
		dp[0][i] = 1; 
	for (int i = 1; i < n + 1; i++) 
	{ 
		for (int j = 0; j < m; j++) 
		{ 
			int x = (i-coins[j] >= 0) ? dp[i - coins[j]][j] : 0; 
			int y = (j >= 1) ? dp[i][j - 1] : 0; 
			dp[i][j] = x + y; 
		} 
	} 
	return dp[n][m - 1]; 
} 


int main() 
{ 
	vector<int> coins = {1,2,3};
	int n = 4; 
	cout << countCoins(coins, n); 
} 

