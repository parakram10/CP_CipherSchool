// https://www.geeksforgeeks.org/alternative-sorting/

#include<bits/stdc++.h>
using namespace std;

vector<int> alternateSort(vector<int> v){
    sort(v.begin(),v.end());
    vector<int> ans;
    int m = v.size()-1, n = 0;
    while(n<m){
        ans.push_back(v[m--]);
        ans.push_back(v[n++]);
    }

    if(v.size()%2!=0) ans.push_back(v[n]);
    return ans;
}

int main(){
    vector<int> v = {1, 6, 9, 4, 3, 7, 8, 2};
    vector<int> ans = alternateSort(v);
    for(int i=0;i<v.size();i++) cout<<ans[i]<<" ";
}