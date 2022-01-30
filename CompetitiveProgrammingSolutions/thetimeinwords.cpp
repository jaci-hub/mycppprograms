//https://www.hackerrank.com/challenges/the-time-in-words/problem?isFullScreen=true

string timeInWords(int h, int m) {
  string hora, min, myt;
  //hour
  if(h==1)
    hora="one";
  else if(h==2)
    hora="two";
  else if(h==3)
    hora="three";
  else if(h==4)
    hora="four";
  else if(h==5)
    hora="five";
  else if(h==6)
    hora="six";
  else if(h==7)
    hora="seven";
  else if(h==8)
    hora="eight";
  else if(h==9)
    hora="nine";
  else if(h==10)
    hora="ten";
  else if(h==11)
    hora="eleven";
  else if(h==12)
    hora="twelve";
  //minutes
  if(m==1)
    min="one";
  else if(m==2)
    min="two";
  else if(m==3)
    min="three";
  else if(m==4)
    min="four";
  else if(m==5)
    min="five";
  else if(m==6)
    min="six";
  else if(m==7)
    min="seven";
  else if(m==8)
    min="eight";
  else if(m==9)
    min="nine";
  else if(m==10)
    min="ten";
  else if(m==11)
    min="eleven";
  else if(m==12)
    min="twelve";
  else if(m==13)
    min="thirteen";
  else if(m==14)
    min="fourteen";
  else if(m==16)
    min="sixteen";
  else if(m==17)
    min="seventeen";
  else if(m==18)
    min="eighteen";
  else if(m==19)
    min="nineteen";
  else if(m==20)
    min="twenty";
  else if(m==21)
    min="twenty one";
  else if(m==22)
    min="twenty two";
  else if(m==23)
    min="twenty three";
  else if(m==24)
    min="twenty four";
  else if(m==25)
    min="twenty five";
  else if(m==26)
    min="twenty six";
  else if(m==27)
    min="twenty seven";
  else if(m==28)
    min="twenty eight";
  else if(m==29)
    min="twenty nine";
  
  if(m==0){
    return hora+" o' clock";
  }
  else if(m==15){
    return "quarter past "+hora;
  }
  else if(m>=1 && m<30){
    if(m>1)
      return min+ " minutes past "+hora;
    else return min+ " minute past "+hora;
  }
  else if(m==30){
    return "half past "+hora;
  }
  else if(m==45){
    if(h==12)
      h=1;
    else h+=1;
  //hour, so it is updated
  if(h==1)
    hora="one";
  else if(h==2)
    hora="two";
  else if(h==3)
    hora="three";
  else if(h==4)
    hora="four";
  else if(h==5)
    hora="five";
  else if(h==6)
    hora="six";
  else if(h==7)
    hora="seven";
  else if(h==8)
    hora="eight";
  else if(h==9)
    hora="nine";
  else if(h==10)
    hora="ten";
  else if(h==11)
    hora="eleven";
  else if(h==12)
    hora="twelve";
  
  return "quarter to "+hora;
  }
  else if(m>30){
    m=60-m;
  //minutes, so it is updated
  if(m==1)
    min="one";
  else if(m==2)
    min="two";
  else if(m==3)
    min="three";
  else if(m==4)
    min="four";
  else if(m==5)
    min="five";
  else if(m==6)
    min="six";
  else if(m==7)
    min="seven";
  else if(m==8)
    min="eight";
  else if(m==9)
    min="nine";
  else if(m==10)
    min="ten";
  else if(m==11)
    min="eleven";
  else if(m==12)
    min="twelve";
  else if(m==13)
    min="thirteen";
  else if(m==14)
    min="fourteen";
  else if(m==16)
    min="sixteen";
  else if(m==17)
    min="seventeen";
  else if(m==18)
    min="eighteen";
  else if(m==19)
    min="nineteen";
  else if(m==20)
    min="twenty";
  else if(m==21)
    min="twenty one";
  else if(m==22)
    min="twenty two";
  else if(m==23)
    min="twenty three";
  else if(m==24)
    min="twenty four";
  else if(m==25)
    min="twenty five";
  else if(m==26)
    min="twenty six";
  else if(m==27)
    min="twenty seven";
  else if(m==28)
    min="twenty eight";
  else if(m==29)
    min="twenty nine";
  
  if(h==12)
      h=1;
    else h+=1;
  //hour, so it is updated
  if(h==1)
    hora="one";
  else if(h==2)
    hora="two";
  else if(h==3)
    hora="three";
  else if(h==4)
    hora="four";
  else if(h==5)
    hora="five";
  else if(h==6)
    hora="six";
  else if(h==7)
    hora="seven";
  else if(h==8)
    hora="eight";
  else if(h==9)
    hora="nine";
  else if(h==10)
    hora="ten";
  else if(h==11)
    hora="eleven";
  else if(h==12)
    hora="twelve";
  
  if(m>1)
    return min+ " minutes to "+hora;
  else return min+ " minute to "+hora;
  }
  return myt;
}