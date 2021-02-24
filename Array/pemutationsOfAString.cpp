// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<bits/stdc++.h>
using namespace std;

void findAllPermutations(string s, vector<string>& res, int i, int n){
    if(i==n){
        res.push_back(s);
        return;
    }
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        findAllPermutations(s,res,i+1,n);
        swap(s[i],s[j]);
    }
}

int main(){
    string s;
    cin>>s;
    vector<string> result;
    int i = 0;
    int n = s.length();
    findAllPermutations(s,result,i,n);

    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
}