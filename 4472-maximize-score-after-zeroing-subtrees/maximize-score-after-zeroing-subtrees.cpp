class Solution {
public:
    int dfs(int i,vector<vector<int>> &adj,vector<int>& op, vector<int>& score){
        int n = adj.size();
        int res = score[i];
        int mn = INT_MAX;
        if(adj[i].empty()) return score[i];
        for(int j : adj[i]) {
            int val = dfs(j, adj, op, score);
            res+=val;
            mn=min(mn,val);
        }

        if(op[i] || mn<0){
            res-=mn;
        }
        return res;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        return dfs(0,adj,op,score);

    }
};