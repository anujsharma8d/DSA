class Solution {
public:
    int getNext(vector<vector<int>> &jobs,int t){
        int n=jobs.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid = low+(high - low)/2;
            if(jobs[mid][0]>=t){
                ans = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }


    int solve(vector<vector<int>> &jobs, int i,vector<int> &dp){
        int n=jobs.size();
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake = solve(jobs,i+1,dp);

        int next = getNext(jobs,jobs[i][1]);
        int take = jobs[i][2]+solve(jobs,next,dp);

        return dp[i]=max(take,nottake);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int> dp(n,-1);
        return solve(jobs,0,dp);
    }
};