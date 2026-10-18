class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int len = 0;
        int freq = 0;

        unordered_map<char,int> mpp;
        while(right < n){
            mpp[s[right]]++;
            freq = max(freq,mpp[s[right]]);

            while((right-left+1)-freq > k){
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
