#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //for sort
#include<cmath>
using namespace std;

//NAME: JACINTO QUIMUA
//Date: 4 APRIL 2021
/*
My goal is to find the nth gray code number using sequences!
*/

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

/*
  This function returns the nth gray code, using a,b,c and d sequences
*/
int G(int n){
  //checking a-sequence
  if((n-2)%4==0)
    return a((n-2)/4)-n;
  else if((n-3)%4==0)
    return a((n-3)/4)-n;
  //checking b-sequence
  else if((n-9)%16==0)
    return b((n-9)/16)-n;
  else if((n-12)%16==0)
    return b((n-12)/16)-n;
  //checking c-sequence
  else if((n-8)%16==0)
    return c((n-8)/16)-n;
  else if((n-13)%16==0)
    return c((n-13)/16)-n+4;
  //checking d-sequence
  else if(n%8==0 && (n/8)%2==0)
    return d(n/8)-n;
  else if((n+4)%8==0 && ((n+4)/8)%2!=0)
    return d((n+4)/8)-n;
  else if((n-1)%8==0 && ((n-1)/8)%2==0)
    return d((n-1)/8)-n+2;
  else if((n+3)%8==0 && ((n+3)/8)%2!=0)
    return d((n+3)/8)-n+2;
  return -1;
}

/*
  This function returns the sequence that n+G(n) belongs to. 
  For example, n=13 implies c-sequence, because n+G(n) = 13+11 = 24, and 24 is part of the c-sequence
*/
string get_sequence(int n){
  //checking a-sequence
  if((n-2)%4==0)
    return "a";
  else if((n-3)%4==0)
    return "a";
  //checking b-sequence
  else if((n-9)%16==0)
    return "b";
  else if((n-12)%16==0)
    return "b";
  //checking c-sequence
  else if((n-8)%16==0)
    return "c";
  else if((n-13)%16==0)
    return "c";
  //checking d-sequence
  else if(n%8==0 && (n/8)%2==0)
    return "d";
  else if((n+4)%8==0 && ((n+4)/8)%2!=0)
    return "d";
  else if((n-1)%8==0 && ((n-1)/8)%2==0)
    return "d";
  else if((n+3)%8==0 && ((n+3)/8)%2!=0)
    return "d";
  return "N/A";
}

/*
  This function returns the subscript of the sequence term. 
  For example, the general term of the a-sequence is a(k), so the function returns k
*/
int get_sequence_term_number(int n){
  //checking a-sequence
  if((n-2)%4==0)
    return (n-2)/4;
  else if((n-3)%4==0)
    return (n-3)/4;
  //checking b-sequence
  else if((n-9)%16==0)
    return (n-9)/16;
  else if((n-12)%16==0)
    return (n-12)/16;
  //checking c-sequence
  else if((n-8)%16==0)
    return (n-8)/16;
  else if((n-13)%16==0)
    return (n-13)/16;
  //checking d-sequence
  else if(n%8==0 && (n/8)%2==0)
    return n/8;
  else if((n+4)%8==0 && ((n+4)/8)%2!=0)
    return (n+4)/8;
  else if((n-1)%8==0 && ((n-1)/8)%2==0)
    return (n-1)/8;
  else if((n+3)%8==0 && ((n+3)/8)%2!=0)
    return (n+3)/8;
  return -1;
}

/*
  This function returns the 0 if the kth term of a sequence is the first one, and 1 otherwise.
  For example the a-sequence has 5 and 5 as its first term, a(0), k=0.
  The point is that it allows us to know if when n=2, for example, which has G(n)=3, which 5 in the a-sequence
  their sum (n+G(n)) refers to. In this case it refers to the first 5, and the second is for when n=3.
*/
int get_sequence_term_number_0th_or_1st(int n){
  //checking a-sequence
  if((n-2)%4==0)
    return 0;
  else if((n-3)%4==0)
    return 1;
  //checking b-sequence
  else if((n-9)%16==0)
    return 0;
  else if((n-12)%16==0)
    return 1;
  //checking c-sequence
  else if((n-8)%16==0)
    return 0;
  else if((n-13)%16==0)
    return 1;
  //checking d-sequence
  else if(n%8==0 && (n/8)%2==0)
    return 0;
  else if((n+4)%8==0 && ((n+4)/8)%2!=0)
    return 0;
  else if((n-1)%8==0 && ((n-1)/8)%2==0)
    return 1;
  else if((n+3)%8==0 && ((n+3)/8)%2!=0)
    return 1;
  return -1;
}

/*
  Gives the cycle of n, which is defined as applying g(n) repeatedly till the result is n again.
*/
int recursion_C(int n){
  int res=n, counter=1;
  while(g(res)!=n){
    res=g(res);
    counter++;
  }
  return counter;
}

int C(int n){
  return n <= 1 ? 1 : pow(2, floor(log2(log2(n)))+1);
}

int main(){
  /*
    NTH GRAY CODE NUMBER
  */
  // string a="Your nth gray code algorithm works!!!";
  // for(int i=0; i<=pow(10,5); i++){ 
  //   if(G(i)!= g(i)){
  //     a="";
  //     cout<<"Wrong for i = "<< i;
  //     break;
  //   }
  // }
  // cout<<a<<"\n";

  /*
    SEQUENCE THAT N BELONGS TO
  */
  // for(int i=0; i<=31; i++){
  //   cout<<i<<": "<<get_sequence(i)<<"\n";
  // }

  /*
    SEQUENCE TERM AND 0th OR 1st
  */
  // for(int n=0; n<=31; n++){
  //   cout<<n<<": "<<sequence_term_number(n)<<" - "<<sequence_term_number_0th_or_1st(n)<<"\n";
  // }

  /*
    CYCLE OF N
  */
  string a="Your cycle algorithm works!!!";
  for(int i=0; i<=pow(10,5); i++){
    if(recursion_C(i)!=C(i)){
      a="";
      cout<<"Failed for i = "<<i<<"\n";
      break;
    }
  }
  cout<<a<<"\n";

  return 0;
}