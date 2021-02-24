// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/


#include<bits/stdc++.h>
using namespace std;

int noOfPlatforms(vector<int> arr, vector<int> dept){
    sort(arr.begin(),arr.end());
    sort(dept.begin(),dept.end());
    int n = arr.size();
    int platforms = 1, ans = 1;
    int i = 1, j = 0;
    while(i<n && j<n){
        if(arr[i]<dept[j]){
            platforms++;
            i++;
        }
        else if(arr[i]>dept[j]){
            platforms--;
            j++;
        }

        ans = max(ans, platforms);
    }

    return ans;
}


int main(){
    vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 };

    cout<<noOfPlatforms(arr,dep);
}