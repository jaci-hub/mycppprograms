//https://www.hackerrank.com/challenges/alternating-characters/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

int alternatingCharacters(string s) {
    int count=0;
    for(int i=0; i<s.size(); i++){
        for(int j=1; j<s.size(); j++){
            if(s[i]==s[j]){
                count++;
                if(s[i]!=s[j]){
                    break;
                }
            }
            i=j;
        }
    }
    return count;
}