//NAME: JACINTO QUIMUA
//Date: 4 APRIL 2021
/*
My goal is to find the nth gray code number using sequences!
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

//g(n) gives the nth gray code
int g (int n) {
  return n ^ (n >> 1);
}

//a-sequence
int a(int k){
if(k==0)
  return 5;
else if(k%2!=0)
  return 2*a((k-1)/2)+1;
else
  return 2*a(k/2)+4*(pow(-1,(k/2)+1))-1;
}
//b-sequence
int b(int k){
  return a(4*k+2)-3;
}
//c-sequence
int c(int k){
  return a(4*k+2)-5;
}
//d-sequence
int d(int k){
  if(k%2 != 0)
    return a(2*k-1)-1;
  else return a(2*k)-5;
}

int G(int n){
  int result;
 for(int k=0; k<=n; k++){
  //checking a-sequence
  if(n==(4*k+2))
    result=a(k)-n;
  else if(n==(4*k+3))
    result=a(k)-n;
  //checking b-sequence
  else if(n==(16*k+9))
    result=b(k)-n;
  else if(n==(16*k+12))
    result=b(k)-n;
  //checking c-sequence
  else if(n==(16*k+8))
    result=c(k)-n;
  else if(n==(16*k+13))
    result=c(k)-n+4;
  //checking d-sequence
  else if(k%2==0 && n==8*k)
    result=d(k)-n;
  else if(k%2!=0 && n==8*k-4)
    result=d(k)-n;
  else if(k%2==0 && n==8*k+1)
    result=d(k)-n+2;
  else if(k%2!=0 && n==8*k-3)
    result=d(k)-n+2;
  }
  return result;
}

bool primos(int res){
  bool valor=true;
      int temp=res/2;
      if(res==0 || res==1)
        valor=false;
      for(int i=2; i<=temp; i++){
        if(res%i == 0){
          valor = false;
          break;
        }
      }
      if(valor)
        return true;
      else return false;
}

vector<int> vistos; //collector

/*int*/void C(int n){ //Gives the cycle of n
int res=n, counter=1;
      cout<<res<<"-> ";
      vistos.push_back(res);
  while(g(res)!=n){
    res=g(res);
    counter++;
      cout<<res<<"-> ";
      vistos.push_back(res);
  }
  cout<<"\n";
  //return counter;
}

int main(){
//  string a="Your algorithm works!!!";
//  for(int i=0; i<=2*pow(10,4); i++){ 
//   if(G(i)!= g(i)){
//     a="";
//     cout<<"Wrong for i = "<< i;
//     break;
//   }
//  }
//   cout<<a<<"\n";

for(double i=0; i<1000; i++){
  sort(vistos.begin(), vistos.end());
  for(int j=0; j<vistos.size(); j++){
    while(i == vistos[j])
      i++;
  }
  C(i);
}

  return 0;
}