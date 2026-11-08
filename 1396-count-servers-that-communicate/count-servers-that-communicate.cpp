class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> nums(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int idx1 = -1;
            int idx2 = -1;
            int count = 0;
            bool take = false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && take){
                    nums[i][j]++;
                    count++;
                }
                if(grid[i][j]==1 && !take){
                    take = true;
                    idx1 = i;
                    idx2 = j;
                }
            }
            if(count>0){
                nums[idx1][idx2]++;
            }
        }
        for(int j=0;j<m;j++){
            int idx1 = -1;
            int idx2 = -1;
            int count = 0;
            bool take = false;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1 && take){
                    nums[i][j]++;
                    count++;
                }
                if(grid[i][j]==1 && !take){
                    take = true;
                    idx1 = i;
                    idx2 = j;
                }
            }
            if(count>0){
                nums[idx1][idx2]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(nums[i][j]!=0){
                    ans++;
                }
            }
        }
        return ans;
    }
};