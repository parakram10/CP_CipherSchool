#include<bits/stdc++.h>
using namespace std;

vector<double> medianOfStreams(vector<double> stream){
    vector<double> res;
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double> > minHeap;
     double top1, top2;
    for(int i=0;i<stream.size();i++){
        maxHeap.push(stream[i]);
        while(maxHeap.size()-minHeap.size()>1){
            double ele = maxHeap.top();
            maxHeap.pop();
            minHeap.push(ele);
        }

        if(maxHeap.size() > minHeap.size()){
            res.push_back(maxHeap.top());
        }
        else if(maxHeap.size() == minHeap.size()){
            top1 = maxHeap.top();
            top2 = minHeap.top();
            res.push_back((top1+top2)/2);
        }
    }
    return res;
}

int main(){
    vector<double> stream = {1,2,3,4,5,6,7,8,9,10};
    vector<double> res = medianOfStreams(stream);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
}