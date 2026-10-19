class Solution {
    bool static cmp(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            if(a.second > b.second)return true;
            else return false;
        }
        else if(a.first > b.first)return true;
        return false;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n==0)return 0;
        vector<pair<int,int>> arr;
        for(int i = 0; i<n; i++){
            arr.push_back({position[i],speed[i]});
        }

        sort(arr.begin(),arr.end(),cmp);

        vector<double> time(n,0);
        for(int i = 0; i<n; i++){
            int val = target - arr[i].first;
            
            time[i] = (double)val / arr[i].second;
        }

        int cnt = 0;
        double prevTime = 0;

        for(int i = 0; i < n; i++) {
            if(time[i] > prevTime) {
                cnt++;
                prevTime = time[i];
            }
        }
        return cnt;
    }
};
