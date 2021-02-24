// https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/


#include<bits/stdc++.h>
using namespace std;

void balancedParenthesisHelper(vector<string>& v, int open, int close, int size, string s){
    
    if(open<0 || close<0 || open>size || close>size || close>open)  return;

    if(close == size && open == size){
        v.push_back(s);
        return;
    }

    balancedParenthesisHelper(v, open+1, close, size, s+"(");
    balancedParenthesisHelper(v, open, close+1, size, s+")");
}

int main(){
    int n;
    cin>>n;
    vector<string> v;
    balancedParenthesisHelper(v,0,0,n," ");
    int k = v.size();
    for(int i=0;i<k;i++) cout<<v[i]<<"\n";
}