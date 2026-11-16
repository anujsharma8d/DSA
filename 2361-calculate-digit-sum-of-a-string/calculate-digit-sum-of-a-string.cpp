class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string ans = "";
            int num = 0;
            for(int i=0;i<s.size();i++){
                num+=s[i]-'0';
                if((i+1)%k==0){
                    ans+=to_string(num);
                    num=0;
                }
            }
            if(s.size()%k!=0){
                ans+=to_string(num);
            }
            s=ans;
        }
        return s;
    }
};