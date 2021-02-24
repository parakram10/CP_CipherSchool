// https://www.geeksforgeeks.org/trapping-rain-water/


#include<bits/stdc++.h>
using namespace std;


int trappedWater(vector<int> v){
    int n = v.size();
    int ans = 0;
    int leftArr[n], rightArr[n];
    
    leftArr[0] = v[0];
    for(int i=1;i<n;i++) leftArr[i] = max(leftArr[i-1],v[i]);
    
    rightArr[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) rightArr[i] = max(rightArr[i+1],v[i]);

    for(int i=1;i<v.size()-1;i++){
        ans+= min(leftArr[i],rightArr[i])-v[i];
    }

    return ans;
}

int main(){
    vector<int> v = {2,0,2};
    int ans = trappedWater(v);
    cout<<ans;
}