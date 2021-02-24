// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


#include<bits/stdc++.h>
using namespace std;

void findPathForRat(int i, int j, int n, vector<vector<int>>& res, string s){
    if(i>=n || j>=n || i<0 || j<0 || res[i][j] == 0) return;
    if(i==n-1 && j==n-1){
        cout<<s<<"\n";
        return;
    }
    else{
        res[i][j] = 0;
        findPathForRat(i+1,j,n,res,s+'D');
        findPathForRat(i-1,j,n,res,s+'U');
        findPathForRat(i,j+1,n,res,s+'R');
        findPathForRat(i,j-1,n,res,s+'L');
        res[i][j] = 1;
    }
}

int main(){
    vector<vector<int>> res = {{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0},{0, 1, 1, 1},{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0},{0, 1, 1, 1}};
    int n = res.size();
    string s = " ";
    findPathForRat(0,0,n,res,s);
}