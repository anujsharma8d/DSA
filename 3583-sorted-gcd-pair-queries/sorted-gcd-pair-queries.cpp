class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        map<int,int> mpp;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int x:nums){
            mpp[x]++;
        }
        vector<long long> count(maxi + 1, 0);
        for(int g=1;g<=maxi;g++){
            for(int j=g;j<=maxi;j+=g){
                count[g]+=mpp[j];
            }
        }
        vector<long long> exact(maxi + 1, 0);

        for(int g=maxi;g>=1;g--){
            exact[g]= count[g]*(count[g]-1)/2;
            for(int j= 2*g;j<=maxi;j+=g){
                exact[g]-=exact[j];
            }
        }

        vector<long long> pref(maxi + 1, 0);

        for(int g=1;g<=maxi;g++){
            pref[g]=pref[g-1]+exact[g];
        }
        vector<int> ans;
        
        for(long long q: queries){
            int g= lower_bound(pref.begin()+1,pref.end(),q+1)-pref.begin();
            ans.push_back(g);
        }
        return ans;
        
    }
};