class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }
        if(visited[i][j]){
            return true;
        }
        visited[i][j]=1;
        bool left = dfs(grid,visited,i-1,j);
        bool right = dfs(grid,visited,i+1,j);
        bool up = dfs(grid,visited,i,j-1);
        bool down = dfs(grid,visited,i,j+1);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0; 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==false && !visited[i][j]){
                    if(dfs(grid,visited,i,j)==true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};