// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;


void findOccurance(int a[], int n, int x){
    int first = 0, last = 0;
    int i = 0;
    for(i=0;i<n;i++) if(a[i] == x){ first = i; break;}

    for(int j=i+1;j<n;j++) if(a[i]==x) last = j;

    cout<<first<<"   "<<last<<"  ";
}


int main(){
    int a[] = {1,3,5,5,5,5,5,67,123,125};
    int n = 10;
    int m = 5;
    findOccurance(a,n,m);
}