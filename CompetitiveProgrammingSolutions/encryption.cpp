//https://www.hackerrank.com/challenges/encryption/problem?isFullScreen=false
//FAILED CASE #12 ONLY!!!!
string encryption(string s) {
    double sqrtOfs=sqrt(s.size());
    int row, col, count=0;
    while(sqrtOfs>0){
        sqrtOfs-=1;
        count++;
    }
    if(sqrtOfs>0){
        row=count;
        col=count+1;
    }
    else{
        row=count;
        col=count;
    }
    if(row*col<s.size()){
        row=count+1;
        col=count+1;
    }
    char arr[row][col];
    int k=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j]=s[k];
            k++;
        }
    }
    string result;
    for(int i=0; i<row; i++){
        if(i==0){
            for(int j=0; j<col; j++){
                if(isalpha(arr[j][i]))
                    result+=arr[j][i];
            }
        }
        else{
            result+=' ';
            for(int j=0; j<col; j++){
                if(isalpha(arr[j][i]))
                    result+=arr[j][i];
            }
        }
    }
    return result;
}
