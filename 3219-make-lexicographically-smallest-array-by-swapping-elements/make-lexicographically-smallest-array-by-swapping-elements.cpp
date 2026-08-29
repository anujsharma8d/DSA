class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(n);

        int start = 0;

        while (start<n) {
            int end=start;

            while (end+1<n && arr[end+1].first-arr[end].first<=limit) {
                end++;
            }
            vector<int> val;
            vector<int> idx;

            for (int i = start; i <= end; i++) {
                val.push_back(arr[i].first);
                idx.push_back(arr[i].second);
            }

            sort(val.begin(),val.end());
            sort(idx.begin(),idx.end());

            
            for (int i = 0; i < val.size(); i++) {
                    ans[idx[i]] = val[i];
            }

            start = end+1;
        }
        return ans;
        
    }
};