class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int left=0;
        int right=0;
        int ans=0;
        while(left<n && right<m){
            if(players[left]<=trainers[right]){
                ans++;
                left++;
                right++;
            }
            else{
                right++;
            }
        }
        return ans;
    }
};