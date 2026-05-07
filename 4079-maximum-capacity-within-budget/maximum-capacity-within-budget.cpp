class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n1=costs.size();
        int n2=capacity.size();
        int maxi=0;
        vector<pair<int,int>> v(n1);
        for(int i=0;i<n1;i++){
            v[i]={costs[i],capacity[i]};
        }
        sort(v.begin(),v.end());
        vector<int> prefixMax(n1);
        prefixMax[0] = v[0].second;
        for(int i = 1; i < n1; i++){
            prefixMax[i] = max(prefixMax[i-1], v[i].second);
        }
        for(int i=0;i<n1;i++){
            if(v[i].first<budget){
                maxi=max(maxi,v[i].second);
            }
        }
        for(int right=1;right<n1;right++){
            int remain=budget-v[right].first;

            int low=0;
            int high=right-1;
            int best=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(v[mid].first<remain){
                    best=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(best!=-1){
                maxi=max(maxi,v[right].second+prefixMax[best]);
            }
        }
        return maxi;
    }
};