// https://www.geeksforgeeks.org/subset-sum-backtracking-4/

#include<bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> v, vector<string>& res, int n, int k, int i, int sum, string currVal){
    if(sum == k){
        res.push_back(currVal);
        return;
    }
    if(i==n) {
        return;
    }
    subsetSum(v,res,n,k,i+1,sum,currVal);
    currVal+=" ";
    currVal+= to_string(v[i]);
    subsetSum(v,res,n,k,i+1,sum+v[i],currVal);
}

int main(){
    vector<int> v = {15, 22, 14, 26, 32, 9, 16, 8};
    int k = 53;
    int n = v.size();
    vector<string> res;
    subsetSum(v,res,n,k,0,0,"");
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }
}