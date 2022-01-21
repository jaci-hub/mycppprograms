//https://leetcode.com/problems/roman-to-integer/submissions/

class Solution {
public:
    int convert(char a){
        int myInt1=0;
        if(a=='I')
            myInt1= 1;
        else if (a=='V')
            myInt1= 5;
        else if (a=='X')
            myInt1= 10;
        else if (a=='L')
            myInt1= 50;
        else if (a=='C')
            myInt1= 100;
        else if (a=='D')
            myInt1= 500;
        else if (a=='M')
            myInt1= 1000;
        return myInt1;
    }
    
    int romanToInt(string s) {
        int result=0;
        for(int i=0; i<s.size(); i++){
            if(convert(s[i])>=convert(s[i+1])){
                result+=convert(s[i]);
            }
            else if(convert(s[i])<convert(s[i+1])) {
                result-=convert(s[i]);
            }
        }
        return result;
    }
};