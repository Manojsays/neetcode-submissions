class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(auto it : nums){
            st.insert(it);
        }

        int maxlen = 0;
        for(auto it: st){
            if (st.find(it - 1) == st.end()) {
                int current = it;
                int len = 0;

                while(st.find(current) != st.end()){
                    len++;
                    current++;
                }

                maxlen = max(maxlen,len);
            }
        }      
        return maxlen;            
    }
};