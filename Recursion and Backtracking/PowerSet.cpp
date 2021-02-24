#include<bits/stdc++.h>
using namespace std;

void powerSet(string s, vector<string>& res, int i, int n, string curr){
    if(i==n){
        res.push_back(curr);
        return;
    }
    powerSet(s,res,i+1,n,curr);
    powerSet(s,res,i+1,n,curr+s[i]);
    
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<string> res;
    powerSet(s,res,0,n,"");
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
}