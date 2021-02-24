#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int> > v = {{2, 6, 12, 34},{1, 9, 20, 1000},{23, 34, 90, 2000}};

    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            maxHeap.push(v[i][j]);
        }
    }
    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
}