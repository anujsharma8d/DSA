class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=knowledge.size();
        unordered_map<string,string> mpp;
        for(int i=0;i<n;i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        string key="";
        bool take=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                take=true;
            }
            if(take && s[i]!='(' && s[i]!=')'){
                key+=s[i];
            }
            if(s[i]==')'){
                take=false;
                if(mpp.find(key)!=mpp.end()){
                    ans+=mpp[key];
                }
                else{
                    ans+='?';
                }
                key="";
                continue;
            }
            if(!take && s[i]!=')'){
                ans+=s[i];
            }
        }
        return ans;
    }
};