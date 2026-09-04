class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> temp;
        int pt1=0;
        int pt2=0;
        while(pt1!=m && pt2!=n){
            if(nums1[pt1]>nums2[pt2]){
                temp.push_back(nums2[pt2]);
                pt2++;
            }
            else{
                temp.push_back(nums1[pt1]);
                pt1++;
            }
        }
        while(pt1!=m){
            temp.push_back(nums1[pt1]);
                pt1++;
        }
        while(pt2!=n){
            temp.push_back(nums2[pt2]);
                pt2++;
        }
        int mid = (m+n)/2;
        if((m+n)%2==0){
            return (temp[mid-1]+temp[mid])/2.0;
        }
        else{
            return (double)temp[mid];
        }
    }
};