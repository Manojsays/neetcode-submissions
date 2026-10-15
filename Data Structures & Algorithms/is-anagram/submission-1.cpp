class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m)return false;

        vector<int> mpp1(26,0);
        vector<int> mpp2(26,0);

        for(int i = 0; i<n; i++){
            mpp1[s[i]-'a']++;
            mpp2[t[i]-'a']++;
        }

        for(int i = 0; i<26; i++){
            if(mpp1[i] != mpp2[i])return false;
        }

        return true;
    }
};
