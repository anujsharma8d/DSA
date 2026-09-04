class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int pt1=0;
        int pt2=0;
        int count=0;

        int size = m+n;
        int idx1= (size-1)/2;
        int idx2= size/2;

        int ans1 = 0;
        int ans2 = 0;

        while(pt1!=m && pt2!=n){
            if(nums1[pt1]>nums2[pt2]){
                if(count==idx1){
                    ans1=nums2[pt2];
                }
                if(count==idx2){
                    ans2=nums2[pt2];
                }
                pt2++;
            }
            else{
                if(count==idx1){
                    ans1=nums1[pt1];
                }
                if(count==idx2){
                    ans2=nums1[pt1];
                }
                pt1++;
            }
                count++;
        }
        while(pt1!=m){
                if(count==idx1){
                    ans1=nums1[pt1];
                }
                if(count==idx2){
                    ans2=nums1[pt1];
                }
                pt1++;
                count++;
        }
        while(pt2!=n){
                if(count==idx1){
                    ans1=nums2[pt2];
                }
                if(count==idx2){
                    ans2=nums2[pt2];
                }
                pt2++;
                count++;
        }
        if((m+n)%2==0){
            return (ans1+ans2)/2.0;
        }
        else{
            return (double)ans2;
        }
    }
};