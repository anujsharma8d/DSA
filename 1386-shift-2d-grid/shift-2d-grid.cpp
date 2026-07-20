class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k = k%(m*n);
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<int> temp1(m*n,0);
        vector<int> temp2(m*n,0);
        int idx=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    temp1[idx]=grid[i][j];
                    idx++;
                }
            }
        idx=0;
        if(k>0){
            for(int i=n*m-k;i<n*m;i++){
                temp2[idx]=temp1[i];
                idx++;
            }
        }
        for(int i=0;i<n*m-k;i++){
            temp2[idx]=temp1[i];
            idx++;
        }
        idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=temp2[idx];
                idx++;
            }
        }
        return ans;


    }
};