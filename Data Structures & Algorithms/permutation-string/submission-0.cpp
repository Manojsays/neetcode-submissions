class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m)return false;
        int k = n;
        vector<int> hash(26,0);

        for(int i = 0; i<n; i++)hash[s1[i]-'a']++;
        int left = 0, right = 0;
        int cnt = 0;
        while(right < m){
            if(hash[s2[right]-'a']>0)cnt++;
            hash[s2[right]-'a']--;
            if(right-left+1 > k){
                if(hash[s2[left]-'a'] >= 0)cnt--;
                hash[s2[left]-'a']++;

                left++;
            }

            if(cnt == n)return true;
            right++;
        }

        return false;
    }
};
