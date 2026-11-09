class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avail_server;
        for(int i=0;i<k;i++){
            avail_server.insert(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy_server;
        vector<int> req_count(k,0);
        for(int i=0;i<arrival.size();i++){
            int time = arrival[i];

            while(!busy_server.empty() && busy_server.top().first<=time){
                int server = busy_server.top().second;
                busy_server.pop();

                avail_server.insert(server);
            }

            int target = i%k;

            auto it = avail_server.lower_bound(target);
            if(it==avail_server.end()){
                it=avail_server.begin();
            }
            if(avail_server.empty()){
                continue;
            }

            int targetServer = *it;

            avail_server.erase(it);

            busy_server.push({time+load[i],targetServer});

            req_count[targetServer]++;
        }

        vector<int> ans;

        int mx = *max_element(req_count.begin(), req_count.end());

        for(int i=0;i<k;i++){
            if(req_count[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;

    }

};