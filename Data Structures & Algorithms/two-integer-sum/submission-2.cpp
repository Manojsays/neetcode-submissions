class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        mpp[nums[0]] = 0;

        for(int i = 1; i<n; i++){
            int required = target - nums[i];
            if(mpp.find(required) != mpp.end()){
                ans.push_back(mpp[required]);
                ans.push_back(i);
                break;
            }

            mpp[nums[i]] = i;
        }
        return ans;
    }
};
