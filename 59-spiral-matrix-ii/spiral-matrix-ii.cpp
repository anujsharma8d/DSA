class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count=1;
        int rowst = 0;
        int colst = 0;
        int rowend = n-1;
        int colend = n-1;
        while(rowst<=rowend && colst<=colend){
            for(int i=colst;i<=colend;i++){
                ans[rowst][i]=count;
                count++;
            }
                rowst++;
            for(int j=rowst;j<=rowend;j++){
                ans[j][colend]=count;
                count++;
            }
                colend--;
            for(int i=colend;i>=colst;i--){
                ans[rowend][i]=count;
                count++;
            }
                rowend--;
            for(int j=rowend;j>=rowst;j--){
                ans[j][colst]=count;
                count++;
            }
                colst++;
        }
        return ans;
    }
};