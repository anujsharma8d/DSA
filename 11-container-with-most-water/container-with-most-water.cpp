class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=-1;
        int st=0;
        int end=n-1;
        while(st<end){   
            int currarea=(min(height[st],height[end]))*(end-st);
            ans=max(ans,currarea);
            if(height[st]<height[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};