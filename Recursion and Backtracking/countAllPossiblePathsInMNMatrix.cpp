// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/

#include<bits/stdc++.h>
using namespace std;

// int findNumberOfPaths(int n, int m){
//     int a[n][m];
//     for(int i=0;i<n;i++) a[i][0] = 1;
//     for(int i=0;i<m;i++) a[0][i] = 1;
//     for(int i=1;i<n;i++){
//         for(int j=1;j<m;j++){
//             a[i][j] = a[i-1][j]+a[i][j-1];
//         }
//     }
//     return a[n-1][m-1];
// }

int findNumberOfPaths(int n, int m){
    int a[m] = {0};
    a[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++) a[j]+=a[j-1];
    }
    return a[m-1];
}


int main(){
    int n,m;
    cin>>n>>m;
    cout<<findNumberOfPaths(n,m);
}