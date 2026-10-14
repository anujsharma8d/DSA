class Solution {
public:
    void solve(int st,vector<int>& candidates,vector<vector<int>> &ans,vector<int> &temp,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=st;i<candidates.size();i++){
            if (i>st && candidates[i]==candidates[i-1]){
                continue;
            }

            if(candidates[i]>target){
                break;
            }

            temp.push_back(candidates[i]);
            solve(i+1,candidates,ans,temp,target-candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,ans,temp,target);
        return ans;
    }
};