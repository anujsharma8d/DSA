class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long total = 0;
        unordered_map<int, int> freq;
        for (int x:nums) {
            total += x;
            freq[x]++;
        }
        int ans=INT_MIN;
        for (int x:nums) {
            long long rem = total - x;
            if (rem % 2) continue;
            long long sumElement = rem / 2;
            freq[x]--;
            if (freq.count(sumElement) && freq[sumElement] > 0) {
                ans = max(ans, x);
            }
            freq[x]++;
        }
        return ans;
    }
};