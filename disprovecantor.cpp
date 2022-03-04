#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    double lookfor=.01, denominator=10, pivot;
    bool founded=false;
    while(true){
        pivot=1.0/denominator;
        cout<<"denominator: "<<denominator<<"\n";
        cout<<"pivot: "<<pivot<<"\n";
        for(double i=0; i<=1; i+=pivot){
            cout<<i<<" ";
            if(lookfor==i){
                founded=true;
                break;
            }
        }
        if(founded)
            break;
        denominator*=10;
    }
    return 0;
}