//https://www.geeksforgeeks.org/majority-element/

#include<bits/stdc++.h>
using namespace std;


int findMajorityElement(vector<int>& v){
    int res = 1;
    int majEle = 0;
    int n = v.size();
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]) res++;
        else res--;

        if(res == 0){
            res = 1;
            majEle = i;
        }
    }
    return majEle;
}


void isPresentElement(vector<int>& v){
    int majEle = findMajorityElement(v);

    int n = v.size();
    int freq = 0;
    for(int i=0;i<n;i++){
        if(v[i] == v[majEle]) freq++;
    }

    if(freq > n/2) cout<<v[majEle]<<" is majority element";
    else cout<<"No majority element is present";
}


int main(){
    vector<int> v = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    isPresentElement(v);

}