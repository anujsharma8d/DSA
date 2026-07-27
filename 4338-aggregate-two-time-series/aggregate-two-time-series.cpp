class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n = series1.size();
        int m = series2.size();
        int first = 0;
        int second = 0;
        vector<vector<int>> ans;
        while(first<n || second<m){
            int a = 0;
            int b = 0;
            int c = INT_MAX;
            int d = INT_MAX;
            if(first<n){
                a = series1[first][1];
                c = series1[first][0];
            }
            if(second<m){
                b = series2[second][1];
                d = series2[second][0];
            }
            int t = min(c,d);
            ans.push_back({t,a+b});
            if(first<n && series1[first][0]==t){
                first++;
            }
            if(second<m && series2[second][0]==t){
                second++;
            }
        }
        return ans;
    }
};