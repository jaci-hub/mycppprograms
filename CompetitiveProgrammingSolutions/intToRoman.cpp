//https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string convert(int a){
        string myString="";
        if(a==1)
            myString= "I";
        else if (a==4)
            myString= "IV";
        else if (a==5)
            myString= "V";
        else if (a==9)
            myString= "IX";
        else if (a==10)
            myString= "X";
        else if (a==40)
            myString= "XL";
        else if (a==50)
            myString= "L";
        else if (a==90)
            myString= "XC";
        else if (a==100)
            myString= "C";
        else if (a==400)
            myString= "CD";
        else if (a==500)
            myString= "D";
        else if (a==900)
            myString= "CM";
        else if (a==1000)
            myString= "M";
        return myString;
    }
    
    vector<int> myVector={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    string intToRoman(int num) {
        string result="";
        int i=0;
        while(num!=0){
            while(num-myVector[i]<0){
                i++;
            }
            num-=myVector[i];
            result+=convert(myVector[i]);
        }
        
        return result;
    }
};