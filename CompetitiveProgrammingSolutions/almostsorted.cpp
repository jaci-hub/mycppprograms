//https://www.hackerrank.com/challenges/almost-sorted/problem?isFullScreen=true

void almostSorted(vector<int> arr) {
  bool sorted=false;
  int pos1=-1, pos2=-1, el1, el2, troca=-1, sizeofarr=arr.size();
  vector<int> sortedarr, myarr, reverseaid;
  sortedarr=arr;
  myarr=arr;
  reverseaid=arr;
  sort(sortedarr.begin(), sortedarr.end());
  if(arr==sortedarr)
    sorted=true;
  else{//SWAP
    for(int i=0; i<sizeofarr; i++){
      if(arr[i]!=sortedarr[i]){
        pos1=i;
        el1=arr[i];
        el2=sortedarr[i];
        break;
      }
    }
    for(int j=pos1+1; j<sizeofarr; j++){
      if(arr[j]==el2){
        pos2=j;
        swap(arr[pos1], arr[pos2]);
        break;
      }
    }
    if(arr==sortedarr)
      troca=1;
    else{//REVERSE
      for(int i=0; i<sizeofarr; i++){
      if(myarr[i]!=sortedarr[i]){
        pos1=i;
        el1=myarr[i];
        el2=sortedarr[i];
        break;
      }
    }
    for(int j=pos1+1; j<sizeofarr; j++){
      if(myarr[j]==el2){
        pos2=j;
        //reverse from pos1 to pos2
        int x=pos2;
        for(int i=pos1; i<=pos2; i++){
          myarr[i]=reverseaid[x];
          x--;
        }
        break;
      }
    }

    if(myarr==sortedarr)
      troca=0;
    }
  }
  
  //result
  if(sorted)
    cout<<"yes";
  else if(troca==1){
    cout<<"yes\n";
    cout<<"swap "<<pos1+1<<" "<<pos2+1;
  }
  else if(troca==0){
    cout<<"yes\n";
    cout<<"reverse "<<pos1+1<<" "<<pos2+1;
  }
  else if(troca==-1)
    cout<<"no";
}
