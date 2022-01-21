#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream dicionario("/usr/share/dict/words"); //english dictionary (case sensitive)

bool isWord(string aa){
  string input;
while(dicionario>>input){
  if(aa ==input)
    return true;
}
return false;
}

int main(){
  string b="my";
  
if(isWord(b))
  cout<<"yes"<<"\n";
else cout<<"no"<<"\n";

  return 0;
}