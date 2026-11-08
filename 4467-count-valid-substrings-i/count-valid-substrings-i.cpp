
class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int last = -1;
        long long ans = 0;

        for(int i=0;i<n;i++){
            if(i>=2 && s[i-2]=='a' && s[i-1]=='b' && s[i]=='c'){
                last = i-2;
            }

            ans += i-last;
        }

        return ans;
    }
};
