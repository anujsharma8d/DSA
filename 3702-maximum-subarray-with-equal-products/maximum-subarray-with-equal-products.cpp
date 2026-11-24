class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i=0;i<n;i++){
                __int128 prod = 1;
                long long l = 1;
                long long g = 0;
            for(int j=i;j<n;j++){
                if(prod > 25200 / nums[j]) break;
                    prod*=nums[j];
                    l = lcm((long long)l,nums[j]);
                    g = gcd((long long)g,nums[j]);
                    if(prod==(__int128)l*g){
                    len = max(len,j-i+1);
                }
            }
        }
        return len;
    }
};