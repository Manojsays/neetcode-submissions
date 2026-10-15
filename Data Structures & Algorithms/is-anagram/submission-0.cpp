class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m)return false;

        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;

        for(int i = 0; i<n; i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }

        for(auto it:mpp1){
            char val = it.first;
            int freq = it.second;

            if(mpp2[val] != freq)return false;
        }

        return true;
    }
};
