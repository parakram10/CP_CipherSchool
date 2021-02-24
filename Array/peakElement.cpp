// https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

#include<bits/stdc++.h>
using namespace std;

vector<int> peakElement(int arr[], int n){
    vector<int> ans;
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) ans.push_back(arr[i]);
    }

    return ans;
}

int main(){
    int arr[] = {5,10,20,15,30,12};
    vector<int> v = peakElement(arr,6);
    int n = v.size();
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}