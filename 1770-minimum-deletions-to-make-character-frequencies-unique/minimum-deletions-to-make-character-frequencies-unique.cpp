class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        vector<int> count;
        for(auto it : mpp){
            count.push_back(it.second);
        }
        sort(count.begin(),count.end());
        int idx1=count.size()-1;
        int ans=0;
        int tempidx=-1;
        while(idx1!=0){
            if(count[idx1]==0){
                tempidx=idx1;
                break;
            }
            if(count[idx1]==count[idx1-1]){
                count[idx1-1]--;
                ans++;
                idx1--;
            }
            else if(count[idx1]<count[idx1-1]){
                ans+=count[idx1-1]-count[idx1]+1;
                count[idx1-1]-=count[idx1-1]-count[idx1]+1;
                idx1--;
            }
            else{
                idx1--;
            }
        }
        if(tempidx!=-1){
            for(int i=tempidx-1;i>=0;i--){
                ans+=count[i];
            }
        }
        return ans;
    }
};