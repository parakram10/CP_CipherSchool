#include <iostream>
using namespace std;

int lcs(string s1, string s2, int i, int j, int res)
{
    if (i == 0 || j == 0)   return res;
 
    if (s1[i - 1] == s2[j - 1]) {
        res = lcs(s1, s2, i - 1, j - 1, res + 1);
    }
    res = max(res,max(lcs(s1, s2, i, j - 1, 0),lcs(s1, s2, i - 1, j, 0)));
    return res;
}
 

int main(){
    int n, m;
    
    string s1 = "HelloWorld";
    string s2 = "HiandHelloWorld";
    cout << lcs(s1, s2, s1.size(), s2.size(), 0);
 
    return 0;
}