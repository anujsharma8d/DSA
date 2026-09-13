class Solution {
public:
    void shift(int n,vector<int> &v,int k){
        k=k%n;
        k=n-k;
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
    } 
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
            shift(n,grid[i],rowShift[i]);
        }
        for(int i=0;i<n;i++){
            vector<int> col;
            int k = colShift[i];
            for(int j=0;j<n;j++){
                col.push_back(grid[j][i]);
            }
            shift(n,col,k);
            for(int l=0;l<n;l++){
                grid[l][i]=col[l];
            }
        }
        return grid;
    }
};