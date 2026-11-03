class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        int n =nums.size();
        for(int i=0;i<n-1;i+=2){
            string s = to_string(nums[i])+to_string(nums[i+1]);
            mini = min(mini,stoi(s));
        }
        return mini;
    }
};