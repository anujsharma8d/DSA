class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool allodd=true;
        bool alleven=true;
        int idx=-1;
        int idx1=-1;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                allodd=false;
            }
            else{
                alleven=false;
            }
            if(idx==-1 && nums1[i]%2==0){
                idx=i;
            }
            
        }
        if(alleven||allodd){
            return true;
        }
        else{
            for(int i=0;i<idx;i++){
                if(nums1[i]%2==1){
                    idx1=i;
                    break;
                }
            }
            if(idx1!=-1){
                return true;
            }
            else{
                return false;
            }
        }

    }
};