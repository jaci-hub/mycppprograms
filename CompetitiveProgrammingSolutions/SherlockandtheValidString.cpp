string isValid(string s) {
    string result="NO";
    int arr[26]={0};
    vector<int>freqCount;
    for(int i=0; i<s.size(); i++){
        arr[int(s[i])-97] += 1;
    }
    for(int i=0; i<26; i++){
        if(arr[i]!=0)
            freqCount.push_back(arr[i]);
    }
    int max_el=*max_element(freqCount.begin(), freqCount.end());
    int min_el=*min_element(freqCount.begin(), freqCount.end());
    
    if(max_el-min_el==0)
        result="YES";
    
    else if(max_el-min_el==1){
        if(min_el==1 && count(freqCount.begin(), freqCount.end(), min_el)==1)
            result="YES";
            
        if(count(freqCount.begin(), freqCount.end(), max_el)==1)
            result="YES";
    }
    
    else if(max_el-min_el>1){
        if(min_el==1 && count(freqCount.begin(), freqCount.end(), min_el)==1){
            sort(freqCount.begin(), freqCount.end(), greater<int>());
            freqCount.pop_back();
        int min_el=*min_element(freqCount.begin(), freqCount.end());
            if(max_el-min_el==0)
                result="YES";
        }   
    }
        
    return result;
}