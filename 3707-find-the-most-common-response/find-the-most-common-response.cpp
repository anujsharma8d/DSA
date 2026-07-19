class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        map<string,int> mpp; 
        for(int i=0;i<n;i++){
            unordered_set <string> st(responses[i].begin(),responses[i].end());
            for(string s:st){
                mpp[s]++;
            }
        }
        string ans=responses[0][0];
        int maxi=0;
        for(auto i:mpp){
            if(i.second>maxi){
                maxi=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};