class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n > m){
            return findMedianSortedArrays(nums2,nums1);
        }

        int low = 0, high = n;
        int k = (n+m)/2;

        while(low <= high){
            int mid1 = (low + high)/2;
            int mid2 = (n + m + 1) / 2 - mid1;

            int left1 = INT_MIN, left2 = INT_MIN;
            int right1 = INT_MAX, right2 = INT_MAX;

            if(mid1 > 0)left1 = nums1[mid1-1];
            if(mid1 < n)right1 = nums1[mid1];
            if(mid2 > 0)left2 = nums2[mid2-1];
            if(mid2 < m)right2 = nums2[mid2];


            if(left1 <= right2 && left2 <= right1){
                if((m+n)%2 == 0){
                    return ((max(left1,left2) + min(right1,right2))/2.0);
                }
                else return (max(left1,left2));
            }


            if(left1 > right2){
                high = mid1-1;
            }
            else low = mid1 + 1;
        }

        return -1;
    }
};
