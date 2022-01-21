//https://leetcode.com/problems/reformat-phone-number/submissions/

class Solution {
public:
    string reformatNumber(string number) {
        string result="";
        int count=0;
        for(int i=0; i<number.size(); i++){
            if(number[i]==' '){
                number.erase(remove(number.begin(), number.end(), ' '), number.end());
            }
        }
        for(int i=0; i<number.size(); i++){
            if(number[i]=='-'){
                number.erase(remove(number.begin(), number.end(), '-'), number.end());
            }
        }
        int length=number.size();
            if(number.size()<4)
                result=number;
            else if(number.size()==4){
                for(int i=0; i<number.size(); i++){
                    if(i==2)
                        result+='-';
                    result+=number[i];
                }
            }
        else if(number.size()>4){
        for(int i=0; i<number.size(); i++){
            if(count==3){
                result+='-';
                count=0;
                length-=3;
                if(length==4){
                    for(int k=number.size()-4; k<number.size(); k++){
                        if(k==number.size()-2)
                            result+='-';
                        result+=number[k];
                    }
                    break;
                }
            }                
            result+=number[i];
            count++;
        }
        }
        return result;
    }
};