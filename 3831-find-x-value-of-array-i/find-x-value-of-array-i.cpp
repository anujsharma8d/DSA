
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            int rem = num % k;

            ndp[rem]++;

            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                ndp[newRem] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                result[r] += ndp[r];
            }

            dp = ndp;
        }

        return result;
    }
};