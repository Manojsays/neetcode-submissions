class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> hash(256,0);
        for(int i = 0; i<m; i++)hash[t[i]]++;

        int left = 0, right = 0;
        int cnt = 0;
        int Sind = -1;
        int len = INT_MAX;

        while(right < n){
            if(hash[s[right]] > 0)cnt++;
            hash[s[right]]--;

            while(cnt >= m){
                if(right-left+1 < len){
                    Sind = left;
                    len = right-left+1;
                }
                if(hash[s[left]]>=0)cnt--;
                hash[s[left]]++;
                left++;
            }

            right++;
        }
        if(Sind == -1)return "";
        return s.substr(Sind,len);
    }
};
