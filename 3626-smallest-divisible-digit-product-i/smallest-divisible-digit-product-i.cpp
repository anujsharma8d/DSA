class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = ceil((double)n/10)*10;
        int ans=num;
        for(int i=n;i<=num;i++){
            int mul=1;
            string s = to_string(i);
            for(int i=0;i<s.size();i++){
                mul *= s[i]-'0';
            }
            if(mul%t==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};