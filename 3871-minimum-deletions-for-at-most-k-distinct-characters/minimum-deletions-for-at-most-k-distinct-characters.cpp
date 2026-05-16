class Solution {
public:
    int minDeletion(string s, int k) {
        int n=s.size();
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto x:mpp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        int ans=0;
        if(v.size()<k){
            return 0;
        }
        for(int i=0;i<v.size()-k;i++){
            ans+=v[i].first;
        }
        return ans;
    }
};