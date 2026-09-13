class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        int count=0;
        for(auto it:mpp){
            bool equalSpaced=true;
            if(it.second.size()>=3){
                for(int i=0;i<it.second.size()-2;i++){
                    if(it.second[i+1]-it.second[i]!=it.second[i+2]-it.second[i+1]){
                        equalSpaced=false;
                        break;
                    }
                }
                if(equalSpaced){
                    count++;
                }
            }
        }
        return count;
    }
};