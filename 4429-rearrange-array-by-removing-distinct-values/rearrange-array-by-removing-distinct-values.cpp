class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(!mpp.empty()){
            for(auto it=mpp.begin();it!=mpp.end();){
                ans.push_back(it->first);
                it->second--;
                if(it->second==0){
                    it=mpp.erase(it);
                }
                else{
                    it++;
                }
            }
        }
        return ans;
    }
};