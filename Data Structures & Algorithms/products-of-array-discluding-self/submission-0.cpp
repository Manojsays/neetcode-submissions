class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        vector<int> ans(n,1);

        prod = 1;
        for(int i = 1; i<n; i++){
            prod *= nums[i-1];
            ans[i] = prod;
        }

        prod = 1;
        for(int i = n-2; i>=0; i--){
            prod *= nums[i+1];
            ans[i] *= prod; 
        }

        return ans;
    }
};
