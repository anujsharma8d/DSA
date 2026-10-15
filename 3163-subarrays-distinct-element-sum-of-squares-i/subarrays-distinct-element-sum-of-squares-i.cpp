class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                set<int> s;
                for(int k=i;k<=j;k++){
                    s.insert(nums[k]);
                }
                int size=s.size();
                ans+=size*size;
            }
        }
        return ans;
    }
};