class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto x:mpp){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end());
        int greater = 0;
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (greater >= k) {
                ans += v[i].second;
            }
            greater += v[i].second;
        }
        return ans;
    }
};