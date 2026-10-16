class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        // unordered_map<vector<int>,string> mpp;

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<strs[i].size(); j++){
        //         mpp.push_back(strs[j]) = i;
        //     }
        // }

        unordered_map<string,vector<string>> mpp;
        for(auto it : strs){
            string s = it;
            sort(s.begin(),s.end());

            mpp[s].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
