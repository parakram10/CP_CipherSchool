// https://www.geeksforgeeks.org/find-possible-words-phone-digits/

#include<bits/stdc++.h>
using namespace std;

vector<string> qwerty = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void phoneDigit(vector<string>& v, string s, int i, string str){
    // if(s.length() == 0) return;
    if(i == s.size()){
        v.push_back(str);
        return;
    }

    string temp = qwerty[s[i]-'0'];
    for(int i=0;i<temp.size();i++){
        str.push_back(temp[i]);
        phoneDigit(v,s,i+1,str);
        str.pop_back();
    }
}

int main(){
    string s;
    cin>>s;
    vector<string> v;
    phoneDigit(v,s,0,"");
    int k = v.size();
    for(int i=0;i<k;i++) cout<<v[i]<<"\n";
}