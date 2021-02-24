// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include<bits/stdc++.h>
using namespace std;

void segregate(vector<int>& v){
    int one = 0, zero = 0, two = v.size()-1;
    while(one<=two){
        if(v[one]==0){
            swap(v[zero],v[one]);
            zero++;
            one++;
        }
        else if(v[one]==1){
            one++;
        }
        else{
            swap(v[one],v[two]);
            two--;
        }
    }
}

int main(){
    vector<int> v = {0,1,1,0,1,2,1,2,0,0,1};
    segregate(v);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}