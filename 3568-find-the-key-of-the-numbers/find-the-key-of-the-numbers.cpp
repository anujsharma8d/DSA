class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1= to_string(num1);
        string s2= to_string(num2);
        string s3= to_string(num3);
        string ans="";
        int mini=min({s1.size(),s2.size(),s3.size()});
        for(int i=0;i<4-mini;i++){
            ans+='0';
        }
        for(int i=mini-1;i>=0;i--){
            ans+=min({s1[s1.size()-1-i],s2[s2.size()-1-i],s3[s3.size()-1-i]});
        }
        return stoi(ans);
    }
};