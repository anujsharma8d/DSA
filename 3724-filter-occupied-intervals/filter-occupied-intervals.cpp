class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        int n= occupiedIntervals.size();
        vector<vector<int>> mergeIntervals;
        mergeIntervals.push_back(occupiedIntervals[0]);
        for(int i=1;i<n;i++){
            if(occupiedIntervals[i][0]<=mergeIntervals.back()[1]+1){
                mergeIntervals.back()[1] = max(mergeIntervals.back()[1],occupiedIntervals[i][1]);
            }
            else{
            mergeIntervals.push_back(occupiedIntervals[i]);
            }
        }
        vector<vector<int>> ans;

        for(int i=0;i<mergeIntervals.size();i++){
            int l = mergeIntervals[i][0];
            int r = mergeIntervals[i][1];

            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
                continue;
            }

            if (l < freeStart) {
                ans.push_back({l, freeStart - 1});
            }

            if (r > freeEnd) {
                ans.push_back({freeEnd + 1, r});
            }
        }
        return ans;
    }
};