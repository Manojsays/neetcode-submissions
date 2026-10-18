class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0, right = n-1;
        int maxi = INT_MIN;
        int area =0;
        while(left < right){

            area = min(heights[left],heights[right]) * (right - left);

            if(heights[left] <= heights[right])left++;
            else right--;
            maxi = max(maxi,area);
        }

        return maxi;
    }
};
