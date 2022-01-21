//https://leetcode.com/problems/merge-strings-alternately/submissions/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int size1=word1.size(), size2=word2.size(), a=0,b=0;
        if(size1>=size2){
        for(int i=0; i<2*size2; i++){
            if(i%2==0){
                result+=word1[a];
                a++;
            }
            else {
                result+=word2[b];
                b++;
            }
        }
            for(int i=size2; i<size1; i++)
                result+=word1[i];
        }
        else if(size1<size2){
           for(int i=0; i<2*size1; i++){
            if(i%2==0){
                result+=word1[a];
                a++;
            }
            else {
                result+=word2[b];
                b++;
            }
            } 
            for(int i=size1; i<size2; i++)
                result+=word2[i];
        }
            
        return result;
    }
};