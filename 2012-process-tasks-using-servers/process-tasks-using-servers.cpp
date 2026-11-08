
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> freeServers;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busyServers;

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) {
            while(!busyServers.empty() && busyServers.top()[0] <= i) {
                vector<long long> curr = busyServers.top();
                busyServers.pop();

                freeServers.push({(int)curr[1], (int)curr[2]});
            }

            if(freeServers.empty()) {
                vector<long long> curr = busyServers.top();
                busyServers.pop();

                result[i] = curr[2];
                busyServers.push({curr[0] + tasks[i], curr[1], curr[2]});
            } 
            else {
                vector<int> curr = freeServers.top();
                freeServers.pop();

                result[i] = curr[1];
                busyServers.push({i + tasks[i], curr[0], curr[1]});
            }
        }

        return result;
    }
};