class Solution {
    vector<int> getPse(vector<int>& heights){
        int n = heights.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    vector<int> getNse(vector<int>& heights){
        int n = heights.size();
        vector<int> nse(n,n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse = getPse(heights);
        vector<int> nse = getNse(heights);

        int area = 0;
        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            area = max(area, width * heights[i]);
        }

        return area;
    }
};
