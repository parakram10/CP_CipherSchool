#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {2,7,11,15};
    int t = 18;
    map<int,int> m;
    for(int i=0;i<v.size();i++){
        m[v[i]] = i;
    }
    vector<int> res;
    for(int i=0;i<v.size();i++){
        int h = t-v[i];
        auto x = m.find(h);
        if(x!=m.end()){
            res.push_back(i);
            res.push_back(x->second);
            break;
        }
    }
    cout<<"[ "<<res[0]<<" , "<<res[1]<<" ]";
}