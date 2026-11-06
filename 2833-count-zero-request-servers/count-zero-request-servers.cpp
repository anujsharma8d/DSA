class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m);
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            int t = q[i].first;
            int idx = q[i].second;

            while(right < logs.size() && logs[right][1] <= t) {
                int id = logs[right][0];

                if(freq[id] == 0) cnt++;

                freq[id]++;
                right++;
            }

            while(left < right && logs[left][1] < t - x) {
                int id = logs[left][0];

                freq[id]--;

                if(freq[id] == 0) cnt--;

                left++;
            }

            ans[idx] = n - cnt;
        }

        return ans;
    }
};