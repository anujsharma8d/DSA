class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int count=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<word.size();i++){
            mpp[word[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto i:mpp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());

        for(int i=v.size()-1;i>=0;i--){
            count++;
            if(count>=9 && count<17){
                ans+=2*v[i].first;
            }
            else if(count>=17 && count<25){
                ans+=3*v[i].first;
            }
            else if(count>=25){
                ans+=4*v[i].first;
            }
            else{
                ans+=1*v[i].first;
            }
        }
        return ans;
    }
};