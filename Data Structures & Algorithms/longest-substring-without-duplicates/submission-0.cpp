class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int len = 0;
        int left = 0, right = 0;
        while(right < n){
            mpp[s[right]]++;
            while(mpp.size() < right-left+1){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0)mpp.erase(s[left]);

                left++;
            }
                len = max(len,right-left+1);
                
            right++;
        }

        return len;
    }
};
