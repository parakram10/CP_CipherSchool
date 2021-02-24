// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/


#include<bits/stdc++.h>
using namespace std;


// Naive Approach

// pair<int, int> searchInSortedMatrix(vector< vector<int> > result, int find){
    
//     pair<int, int> ans;
//     int n = result.size();
//     int m = result[0].size();
//     for(int i=0;i<n;i++){
//         int a = result[i][0];
//         int b = result[i][m-1];
//         if(find>a && find<b){
//             for(int j=0;j<m;j++){
//                 if(result[i][j] == find){
//                     ans.first = i;
//                     ans.second = j;
//                 }
//             }
//         }
//     }
//     return ans;
// }



pair<int,int> searchInSortedMatrix(vector< vector<int> > mat, int find){

    pair<int, int> p;

    int n = mat.size();
    int m = mat[0].size();
    int smallestEle = mat[0][0];
    int largestEle = mat[n-1][m-1];
    
    if(n==0) return p;

    if(find<smallestEle || find>largestEle) return p;

    int i = 0, j = m-1;
    while(i<n && j>=0){
        if(mat[i][j] == find){
            p.first = i;
            p.second = j;
            break;
        }

        else if(find > mat[i][j]) i++;

        else j--;
    }

    return p;
}



int main(){
    // vector<vector<int> > result( n, vector<int> (m,0));
    pair<int, int> p;

    vector< vector<int> > mat = { {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 28, 29, 48}, {32, 33, 39, 50}};
    
    int find = 28;

    p = searchInSortedMatrix(mat, find);

    cout<<"( "<<p.first<<" , "<<p.second<<" )";
}