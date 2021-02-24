// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

#include<bits/stdc++.h>
using namespace std;

void printInSprial(vector< vector<int> > matrix, vector<int>& ans){

    int n = matrix.size();
    int m = matrix[0].size();
    int rs = 0, re = n, cs = 0, ce = m;
    while(rs<re && cs<ce){
        for(int i=cs;i<ce;i++){
            ans.push_back(matrix[rs][i]);
        }
        rs++;
        for(int j=rs;j<re;j++){
            ans.push_back(matrix[j][ce-1]);
        }
        ce--;
        if(rs<re){
            for(int i = ce-1;i>=cs;i--){
                ans.push_back(matrix[re-1][i]);
            }
            re--;
        }
        if(cs<ce){
            for(int i=re-1;i>=rs;i--){
                ans.push_back(matrix[i][cs]);
            }
            cs++;
        }
    } 
}


int main(){
    vector< vector<int> > matrix { { 1, 2, 3, 4, 5, 6 },
                    { 7, 8, 9, 10, 11, 12 },
                    { 13, 14, 15, 16, 17, 18 } };
    vector<int> ans;
    printInSprial(matrix, ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}