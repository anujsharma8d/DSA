class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool appear = false;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                appear=true;
            }
            if(appear && s[i]=='a'){
                return false;
            }
        }
        return true;
    }
};