// https://www.geeksforgeeks.org/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;


int buyAndSell(vector<int> v){
    if(v.size() == 0) return 0;
    int k = v[0];
    int profit = 0, maxProfit = INT_MIN;
    for(int i=0;i<v.size();i++){
        if(v[i]<k) k = v[i];
        profit = v[i]-k;
        if(maxProfit<profit) maxProfit = profit;
    }
    return maxProfit;
}


int main(){
    vector<int> v = { 7, 10, 5, 3, 10, 4 };
    int profit = buyAndSell(v);
    cout<<profit;
}