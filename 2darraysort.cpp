#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,1,2,3,3};
    vector<vector<int>>res(3, vector<int>(2));
    vector<vector<int>>::iterator iter=res.begin();
    int count=0, temp=arr[0], pos=0;
    for(int i=0; i<arr.size(); i++){
        if(temp!=arr[i]){
            res[pos][0]=temp;
            res[pos][1]=count;
            temp=arr[i];
            count=0;
            pos++;
            i--;
        }
        else count++;
    }
    for(int i=0; i<res.size(); i++){
        cout<<res[i][0]<<", "<<res[i][1]<<"\n";
    }
    cout<<endl;
    return 0;
}