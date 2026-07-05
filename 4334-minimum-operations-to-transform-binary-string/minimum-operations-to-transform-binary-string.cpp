class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        int count=0;
        int idx=0;
        while(idx<n){
            if(s1[idx]==s2[idx]){
                idx++;
                continue;
            }
            if(s1[idx]=='0'){
                s1[idx]='1';
                count++;
                idx++;
            }
            else{
                if(idx+1<n){
                    if(s1[idx+1]=='0'){
                        s1[idx+1]='1';
                        count++;
                    }
                    s1[idx]='0';
                    s1[idx+1]='0';
                    count++;
                    idx++;
                }
                else if(idx-1>=0){
                    if(s1[idx-1]=='0'){
                        s1[idx-1]='1';
                        count++;
                    }
                    s1[idx-1]='0';
                    s1[idx]='0';
                    count++;
                    if(s1[idx-1]!=s2[idx-1]){
                        s1[idx-1]='1';
                        count++;
                    }
                }
                else{
                    return -1;
                }
            }
        }
            if(s1==s2){
                return count;
            }
            else{
                return -1;
            }   
        
    }
};