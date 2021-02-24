// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

#include<bits/stdc++.h>
using namespace std;


class petrolPump{
    public:
        int petrol;
        int distance;
};


int petrolpump(vector<petrolPump> v){
    int n = v.size();
    int i = 0;
    int j = 1;

    int curr = v[i].petrol-v[i].distance;

    while(i!=j || curr<0){
        while(curr<0 && i!=j){
            curr = curr - ( v[i].petrol - v[i].distance);
            i = (i+1)%n;

            if(i == 0) return -1;
        }

        curr += v[j].petrol - v[j].distance;

        j = (j+1) % n;
    }

    return i;
}


int main(){
    vector<petrolPump> pet = {{6,4}, {3,6}, {7,3}};
    int start = petrolpump(pet);
    cout<<start;
}