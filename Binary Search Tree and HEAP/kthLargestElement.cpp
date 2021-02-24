#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {5,3,4,7,10,90,32,33,81};
    int k = 3;
    priority_queue<int> maxHeap;
    for(int i=0;i<v.size();i++){
        maxHeap.push(v[i]);
    }
    while(k!=1){
        maxHeap.pop();
        k--;
    }
    cout<<maxHeap.top();
}