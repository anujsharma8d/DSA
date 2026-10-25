class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<int> gain;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            string s = to_string(nums[i]);
            sort(s.rbegin(),s.rend());
            gain.push_back(stoi(s)-nums[i]);
        }
        sort(gain.rbegin(), gain.rend());
        for(int i=0;i<k;i++){
            sum+=gain[i];
        }

        return sum;

    }
};