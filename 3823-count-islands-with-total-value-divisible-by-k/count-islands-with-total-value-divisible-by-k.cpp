class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j,long long &sum){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0){
            return;
        }
        if(grid[i][j]==0 || visited[i][j]){
            return;
        }
        if(grid[i][j]!=0){
            sum+=grid[i][j];
        }
        visited[i][j]=true;
        dfs(grid,visited,i-1,j,sum);
        dfs(grid,visited,i+1,j,sum);
        dfs(grid,visited,i,j-1,sum);
        dfs(grid,visited,i,j+1,sum);

    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum = 0;
                if(grid[i][j]!=0 && !visited[i][j]){
                    dfs(grid,visited,i,j,sum);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};