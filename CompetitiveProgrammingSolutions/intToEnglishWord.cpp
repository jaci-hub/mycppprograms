//https://leetcode.com/problems/integer-to-english-words/submissions/

class Solution {
public:
    vector<int> myVector={1000000000,1000000,1000,100,90,80,70,60,50,40,30,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    
    string convert(int a){
        string myString="";
        if(a==1)
            myString="One";
        else if(a==2)
            myString="Two";
        else if(a==3)
            myString="Three";
        else if(a==4)
            myString="Four";
        else if(a==5)
            myString="Five";
        else if(a==6)
            myString="Six";
        else if(a==7)
            myString="Seven";
        else if(a==8)
            myString="Eight";
        else if(a==9)
            myString="Nine";
        else if(a==10)
            myString="Ten";
        else if(a==11)
            myString="Eleven";
        else if(a==12)
            myString="Twelve";
        else if(a==13)
            myString="Thirteen";
        else if(a==14)
            myString="Fourteen";
        else if(a==15)
            myString="Fifteen";
        else if(a==16)
            myString="Sixteen";
        else if(a==17)
            myString="Seventeen";
        else if(a==18)
            myString="Eighteen";
        else if(a==19)
            myString="Nineteen";
        else if(a==20)
            myString="Twenty";
        else if(a==30)
            myString="Thirty";
        else if(a==40)
            myString="Forty";
        else if(a==50)
            myString="Fifty";
        else if(a==60)
            myString="Sixty";
        else if(a==70)
            myString="Seventy";
        else if(a==80)
            myString="Eighty";
        else if(a==90)
            myString="Ninety";
        else if(a==100)
            myString="One Hundred";
        else if(a==1000)
            myString="One Thousand";
        else if(a==1000000)
            myString="One Million";
        else if(a==1000000000)
            myString="One Billion";
        else{
            int i=0, count=0;
            string blankSpace = "";
            while(a!=0){
                while(a-myVector[i] < 0)
                    i++;
                if(i<4){
                    while(a-myVector[i]>=0){
                        a-=myVector[i];
                        count++;
                    }
                    string newConvertedmyVector;
                    if(myVector[i]==100)
                        newConvertedmyVector="Hundred";
                    else if(myVector[i]==1000)
                        newConvertedmyVector="Thousand";
                    else if(myVector[i]==1000000)
                        newConvertedmyVector="Million";
                    else if(myVector[i]==1000000000)
                        newConvertedmyVector="Billion";
                    myString+=blankSpace + convert(count)+" "+ newConvertedmyVector;
                    count=0;
                }
                else{
                    a-=myVector[i];
                    myString+=blankSpace+convert(myVector[i]);
                }
                blankSpace = " ";
            }
        }
        return myString;
    }
    
    string numberToWords(int num) {
        string result="";
        if(num==0)
            result = "Zero";
        else
            result = convert(num);
        return result;
    }
};