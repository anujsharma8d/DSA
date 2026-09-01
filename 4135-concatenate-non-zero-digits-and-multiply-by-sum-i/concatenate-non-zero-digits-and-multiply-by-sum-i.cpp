class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string ans = "";
        for(char c:s){
            if(c!='0'){
                ans+=c;
            }
        }
        if (ans.empty()) return 0;
        int sum=0;
        for(char c:ans){
            sum+=c-'0';
        }
        int x = stoi(ans);
        return (1LL)*x*sum;
    }
};