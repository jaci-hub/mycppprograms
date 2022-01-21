#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int>a={1, 2, 3};
  vector<int>b={1, 3, 2};
  string s1="23", s2="23";

 int count = 0;
 sort(s2.begin(), s2.end());
 while(next_permutation(s2.begin(), s2.end())){
    // for(int i=0; i<3; i++){
    //     if(a[i]==b[i])
    //         count++;
    // }
    // cout<<count<<"\n";
    // count=0;

    if(s1==s2){
      cout<<s1<<" = "<<s2<<"\n";
      break;
    }
  }
  
  return 0;
}