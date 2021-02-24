// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/


#include<bits/stdc++.h>
using namespace std;


int findLargestSum(vector<int> v){
    int n = v.size();
    int curr_sum = v[0];
    int ans = v[0];
    for(int i=1;i<n;i++){
        curr_sum = max(v[i], curr_sum+v[i]);
        ans = max(ans, curr_sum);
    }

    return ans;
}


int main(){
    vector<int> v = {-1,-10,5,-1,2,-5};
    cout<<findLargestSum(v);
}