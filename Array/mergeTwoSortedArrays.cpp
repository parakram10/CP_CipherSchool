// https://www.geeksforgeeks.org/merge-two-sorted-arrays/


#include<bits/stdc++.h>
using namespace std;

vector<int> mergedArray(vector<int> arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i=0, j=0;
    vector<int> res;
    while(i!=n && j!=m){
        if(arr1[i]<=arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }
        else{
            res.push_back(arr2[j]);
            j++;
        }
    }

    while(i!=n){
        res.push_back(arr1[i]);
        i++;
    }

    while(j!=m){
        res.push_back(arr2[j]);
        j++;
    }

    return res;
}

int main(){
    vector<int> arr1 = {1,3,4,5,12,22};
    vector<int> arr2 = {2,4,6,8,15};
    vector<int> res = mergedArray(arr1,arr2);
    int n = res.size();
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
}