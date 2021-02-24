// https://www.geeksforgeeks.org/find-the-missing-number/


#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1, 2, 4, 6, 3, 7, 8, 9, 5};
    int n = v.size();
    int k = 1;
    for(int i=2;i<=n+1;i++) k = k^i;
    for(int i=0;i<n;i++) k = k^v[i];
    cout<<k;
}