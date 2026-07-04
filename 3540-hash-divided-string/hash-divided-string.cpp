class Solution {
public:
    string stringHash(string s, int k) {
        string result="";
        int count=0;
        int c=0;
        for(int i=0;i<s.size();i++){
            count+=s[i]-'a';
            c++;
            if(c==k){
                char ans='a'+(count%26);
                result+=ans;
                c=0;
                count=0;
            }
        }
        return result;
    }
};