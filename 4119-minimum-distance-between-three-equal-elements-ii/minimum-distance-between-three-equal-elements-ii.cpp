class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it:pos){
            if((it.second).size()>=3){
                for(int i=0;i<(it.second).size()-2;i++){
                    ans=min(ans,2*abs((it.second)[i+2]-(it.second)[i]));
                }
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};