class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        deque<int> dq;
        vector<int> ans;

        while(right < n){
            if(!dq.empty() && dq.front() + k  -1 < right){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            if(right+1 >= k){
                ans.push_back(nums[dq.front()]);
            }

            right++;
        }

        return ans;
    }
};
