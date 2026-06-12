class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int n1=buildings.size();
        unordered_map<int,int> rowmin,rowmax;
        unordered_map<int,int> colmin,colmax;
        for(auto &a:buildings){
            int x=a[0];
            int y=a[1];
            if(!rowmin.count(y)){
                rowmin[y]=rowmax[y]=x;
            }
            else{
                rowmin[y]=min(rowmin[y],x);
                rowmax[y]=max(rowmax[y],x);
            }
            if(!colmin.count(x)){
                colmin[x]=colmax[x]=y;
            }
            else{
                colmin[x]=min(colmin[x],y);
                colmax[x]=max(colmax[x],y);
            }
        }
        int ans=0;
        for(auto &a:buildings){
            int x=a[0];
            int y=a[1];
            if(rowmin[y]<x && rowmax[y]>x && colmin[x]<y && colmax[x]>y ){
                ans++;
            }
        }
        return ans;
    }
};