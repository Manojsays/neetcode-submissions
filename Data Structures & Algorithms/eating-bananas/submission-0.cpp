class Solution {
    int check(int mid,vector<int>& nums){
        int n = nums.size();

        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt += ceil((double)nums[i]/mid);
        }

        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int low = 1;
       int high = *max_element(piles.begin(),piles.end());

       while(low <= high){
        int mid = (low + high)/2;

        if(check(mid,piles) <= h){
             high = mid - 1;
        }
        else low = mid + 1;
       } 

       return low;
    }
};
