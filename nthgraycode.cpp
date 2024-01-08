#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //for sort
#include<cmath>
#include<fstream>
#include<map>
using namespace std;

//NAME: JACINTO QUIMUA
//Date: 4 APRIL 2021
/*
My goal is to find the nth gray code number using sequences!
*/

//Returns the nth gray code
unsigned long long int g (unsigned long long int n) {
  return n ^ (n >> 1);
}

//a-sequence
unsigned long long int a(unsigned long long int k){
if(k==0)
  return 5;
else if(k%2!=0)
  return 2*a((k-1)/2)+1;
else
  return 2*a(k/2)+4*(pow(-1,(k/2)+1))-1;
}
//b-sequence
unsigned long long int b(unsigned long long int k){
  return a(4*k+2)-3;
}
//c-sequence
unsigned long long int c(unsigned long long int k){
  return a(4*k+2)-5;
}
//d-sequence
unsigned long long int d(unsigned long long int k){
  if(k%2 != 0)
    return a(2*k-1)-1;
  else return a(2*k)-5;
}

/*
  Returns the nth gray code, using a,b,c and d sequences
*/
unsigned long long int G(unsigned long long int n){
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
  Returns the sequence that n+G(n) belongs to. 
  For example, n=13 implies c-sequence, because n+G(n) = 13+11 = 24, and 24 is part of the c-sequence
*/
string get_sequence(unsigned long long int n){
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
  Returns the index of the sequence term. 
  For example, the general term of the a-sequence is a(k), so the function returns k
*/
unsigned long long int get_sequence_index(unsigned long long int n){
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
  Returns 0 if the kth term of a sequence is the first one, and 1 otherwise.
  For example the a-sequence has 5 and 5 as its first term, a(0), k=0.
  The point is that it allows us to know if when n=2, for example, which has G(n)=3, which 5 in the a-sequence
  their sum (n+G(n)) refers to. In this case it refers to the first 5, and the second is for when n=3.
*/
unsigned long long int get_0th_or_1st(unsigned long long int n){
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
  Returns the cycle of n, which is defined as applying g(n) repeatedly till the result is n again.
*/
unsigned long long int C_with_loop(unsigned long long int n){
  int res=n, counter=1;
  while(g(res)!=n){
    res=g(res);
    counter++;
  }
  return counter;
}

unsigned long long int C(unsigned long long int n){
  return n <= 1 ? 1 : pow(2, floor(log2(log2(n)))+1);
}

unsigned long long int substring_occurrences_in_a_string(string pattern, string some_string){
  unsigned long long int occurrence=0, left_bound=0, right_bound=pattern.size()-1;
  if(pattern.size() > some_string.size()){
    return 0;
  }
  else if(pattern == some_string){
    return 1;
  }
  else{
    while(right_bound<some_string.size()){
      string substring = "";
      for(int i=left_bound; i<=right_bound; i++){
        substring+=some_string[i];
      }
      if(substring==pattern){
        occurrence++;
      }
      left_bound++;
      right_bound++;
    }
  }
  return occurrence;
}

/*
  Returns the frequency of a sequence term;
  IMPORTANT: This function is only applicable for sequences in
              intervals where log2cycle > 2 aka l>2
*/
int get_frequency(int l, string sequence, int index){
  if(l == 2){
    return 1;
  }
  else if(l > 2){
    int index_const_part = pow(2, pow(2, l-1)-4)-1;
    //checking a-sequence
    if(sequence == "a"){
      //first a
      if(index%4==0){
        return (index/4)-index_const_part;
      }
      //second a
      else if((index-1)%4==0){
        return ((index-1)/4)-index_const_part;
      }
      //third a
      else if((index-2)%4==0){
        return ((index-2)/4)-index_const_part;
      }
      //fourth a
      else if((index-3)%4==0){
        return ((index-3)/4)-index_const_part;
      }
    }
    //checking b-sequence
    if(sequence == "b"){
      return index - index_const_part;
    }
    //checking c-sequence
    if(sequence == "c"){
      return index - index_const_part;
    }
    //checking d-sequence
    if(sequence == "d"){
      //first d
      if(index%2==0){
        return (index/2)-index_const_part;
      }
      //second d
      else if((index-1)%2==0){
        return ((index-1)/2)-index_const_part;
      }
    }
  }
  return -1;
}

/*
  Returns the index of a sequence term in the dacbabca pattern, if l=2 and dadacbabca pattern, if l>2
*/
int get_pattern_index(int l, string sequence, int index, int is0thor1st = 0){
  //checking a-sequence
  if(sequence == "a"){
    if(l == 2){
      if(index == 1){
        return 1;
      }
      else if(index == 2){
        return 4;
      }
    }
    if(l>2){
      if(index%4==0){
        return 1;
      }
      else if(index%2==0 && index%4!=0){
        return 6;
      }
      else if((index-1)%4==0){
        return 3;
      }
      else if((index-3)%4==0){
        return 9;
      }
    }
  }
  //checking b-sequence
  if(sequence == "b"){
    if(l == 2){
      if(is0thor1st == 0){
        return 3;
      }
      else if(is0thor1st == 1){
        return 5;
      }
    }
    if(l > 2){
      if(is0thor1st == 0){
        return 5;
      }
      else if(is0thor1st == 1){
        return 7;
      }
    }
  }
  //checking c-sequence
  if(sequence == "c"){
    if(l == 2){
      if(is0thor1st == 0){
        return 2;
      }
      else if(is0thor1st == 1){
        return 6;
      }
    }
    if(l > 2){
      if(is0thor1st == 0){
        return 4;
      }
      else if(is0thor1st == 1){
        return 8;
      }
    }
  }
  //checking d-sequence
  if(sequence == "d"){
    if(l == 2){
      if(index == 1){
        return 0;
      }
    }
    if(l > 2){
      if(index%2 == 0){
        return 0;
      }
      else{
        return 2;
      }
    }
  }

  return -1;
}

int main(){
  /*
    NTH GRAY CODE NUMBER
  */
  // string a="Your nth gray code algorithm works!!!";
  // for(unsigned long long int i=0; i<=pow(10,5); i++){ 
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
  // for(unsigned long long int i=0; i<=31; i++){
  //   cout<<i<<": "<<get_sequence(i)<<"\n";
  // }

  /*
    SEQUENCE TERM AND 0th OR 1st
  */
  // for(unsigned long long int n=0; n<=31; n++){
  //   cout<<n<<": "<<get_sequence_index(n)<<" - "<<get_0th_or_1st(n)<<"\n";
  // }

  /*
    CYCLE OF N
  */
  // string a="Your cycle algorithm works!!!";
  // for(unsigned long long int i=0; i<=pow(10,5); i++){
  //   if(C_with_loop(i)!=C(i)){
  //     a="";
  //     cout<<"Failed for i = "<<i<<"\n";
  //     break;
  //   }
  // }
  // cout<<a<<"\n";

  /*
    PRINT NUMBERS WITH ALL THEIR INFO
  */
  //ofstream fout;
  //** print n<=1
  // fout.open("sequences_log2cycle_0.csv");
  // fout<<"n\tsequence\tkth term\t0th or 1st\tlog2 Cn\n";
  // for(unsigned long long int i=0; i<=1; i++){
  //   unsigned long long int log2cycle = log2(C(i));
  //   fout<<to_string(i)+"\t"+get_sequence(i)+"\t"+to_string(get_sequence_index(i))+"\t"+to_string(get_0th_or_1st(i))+"\t"+to_string(log2cycle)+"\n";
  // }
  // fout.close();
  //** print n>1
  // for(int j=0; j<=3; j++){
  //   fout.open("sequences_log2cycle_"+to_string(j+1)+".csv");
  //   fout<<"n\tsequence\tkth term\t0th or 1st\tlog2 Cn\n";
  //   for(unsigned long long int i=pow(2, pow(2, j)); i<=pow(2, pow(2, j+1))-1; i++){
  //     unsigned long long int log2cycle = log2(C(i));
  //     fout<<to_string(i)+"\t"+get_sequence(i)+"\t"+to_string(get_sequence_index(i))+"\t"+to_string(get_0th_or_1st(i))+"\t"+to_string(log2cycle)+"\n";
  //   }
  //   fout.close();
  //   cout<<"* Finished j = "<<j<< " *\n";
  // }

  /*
    OCCURRENCES OF THE "dadacbabca" PATTERN per log2 Cn interval
  */
  // fout.open("pattern_occurrence_per_log2cycle.csv");
  // string pattern, log2cycle_sequences="";
  // unsigned long long int i, occurrence=0;
  // fout<<"log2 Cn\tpattern\toccurrence\n";
  // /*
  //   IMPORTANT: Note that there is not need to analyze log2cycle=0 and log2cycle=1, 
  //   because those ALWAYS have only one sequence, d0 and a0, respectively.
  // */
  // for(int j=1; j<=3; j++){
  //   for(i=pow(2, pow(2, j)); i<=pow(2, pow(2, j+1))-1; i++){
  //     log2cycle_sequences+=get_sequence(i);
  //   }
  //   i-=1;
  //   unsigned long long int log2cycle = log2(C(i));
  //   if(j==1){
  //     pattern = "ddaacbaabcaa";
  //   }
  //   else{
  //     pattern = "ddaaddaacbaabcaa";
  //   }
  //   occurrence = substring_occurrences_in_a_string(pattern, log2cycle_sequences);
  //   fout<<to_string(log2cycle)+"\t"+pattern+"\t"+to_string(occurrence)+"\n";
  //   log2cycle_sequences.clear();

  //   cout<<"* Finished j = "<<j<< " *\n";
  // }
  // fout.close();

  /*
    GET FREQUENCY OF SEQUENCE TERM IN THE PATTERN dadacbabca
  */
  int l=2;
  string sequence="d";
  int index=1;
  cout<<"sequence_index\tfrequency\n";
  cout<<sequence+"_"<<index<<"\t"<<get_frequency(l, sequence, index)<<"\n";

  /*
    PATTERN INDEX
  */
  // string sequence="d";
  // int l=2, index=1, is0thor1st=0;
  // cout<<"sequence_index\tpattern index\n";
  // cout<<sequence+"_"<<index<<"\t"<<get_pattern_index(l, sequence, index, is0thor1st)<<"\n";

  return 0;
}