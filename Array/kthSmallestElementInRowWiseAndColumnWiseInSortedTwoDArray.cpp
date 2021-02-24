// https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/


#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector< vector<int> > v, int k){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            q.push(v[i][j]);
        }
    }
    for(int i=0;i<k-1;i++){
        q.pop();
    }
    return q.top();
}

int main(){
    vector<vector<int>> v { { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },};
    int k = 6;
    cout<<kthSmallest(v,k);
}