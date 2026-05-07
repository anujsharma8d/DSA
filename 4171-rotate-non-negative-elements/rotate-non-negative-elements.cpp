class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        vector<pair<int,int>> idx;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                count++;
                idx.push_back({nums[i],i});
            }
        }
        int m=idx.size();
        if(m==0) return nums;
        int rot=k%m;
        vector<int> rotated(m);
        for(int i=0;i<m;i++){
            rotated[i]=idx[(i+rot)%m].first;
        }
        for(int i=0;i<m;i++){
            nums[idx[i].second]=rotated[i];
        }
        return nums;
    }
};