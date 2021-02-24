// https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/


#include<bits/stdc++.h>
using namespace std;

void segregate(vector<int>& v){
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        if(v[i]==1 && v[j]==0){
            swap(v[i],v[j]);
            i++;
            j--;
        }
        else if(v[i]==1 && v[j]==1){
            j--;
        }
        else i++;
    }
}

int main(){
    vector<int> v = {1,0,1,0,1,0,0,1,1,1,0,1};
    segregate(v);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}