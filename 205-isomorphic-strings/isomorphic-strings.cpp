class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char> mpp1;
        map<char,char> mpp2;
        bool check1=true;
        bool check2=true;
        for(int i=0;i<n;i++){
            if(mpp1.find(s[i])!=mpp1.end()){
                if(mpp1[s[i]]!=t[i]){
                    check1 = false;
                    break;
                }
            }
            mpp1[s[i]]=t[i];
        }
        for(int i=0;i<n;i++){
            if(mpp2.find(t[i])!=mpp2.end()){
                if(mpp2[t[i]]!=s[i]){
                    check2 = false;
                }
            }
            mpp2[t[i]]=s[i];
        }
        return check1&&check2;
    }
};