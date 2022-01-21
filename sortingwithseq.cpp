#include<bits/stdc++.h>
#include<cmath>
using namespace std;

tuple<int, int, int> pqm(int n){
  int p, q, m;
 for(int k=0; k<=n; k++){
  //checking a-sequence
  if(n==(4*k+2)){
    p=k;
    q=0;
    m=0;
  }
  else if(n==(4*k+3)){
    p=k;
    q=1;
    m=0;
  }
  //checking b-sequence
  else if(n==(16*k+9)){
    p=4*k+2;
    q=0;
    m=3;
  }
  else if(n==(16*k+12)){
    p=4*k+2;
    q=1;
    m=3;
  }
  //checking c-sequence
  else if(n==(16*k+8)){
    p=4*k+2;
    q=0;
    m=5;
  }
  else if(n==(16*k+13)){
    p=4*k+2;
    q=1;
    m=1;
  }
  //checking d-sequence
  else if(k%2==0 && n==8*k){
    p=2*k;
    q=0;
    m=5;
  }
  else if(k%2!=0 && n==8*k-4){
    p=2*k-1;
    q=0;
    m=1;
  }
  else if(k%2==0 && n==8*k+1){
    p=2*k;
    q=1;
    m=3;
  }
  else if(k%2!=0 && n==8*k-3){
    p=2*k-1;
    q=1;
    m=1;
  }
  }
  return {p, q, m};
}

/*Sorting with the sequences*/
vector<int> mysort(vector<int>& A){
  int p, q, m;
  vector<int> B(A.size());
  for(int i=0; i<A.size(); i++){
    tie(p,q,m)=pqm(A[i]);
    //como preencher B??
  }
  return B;
}

int main(){
  

  return 0;
}