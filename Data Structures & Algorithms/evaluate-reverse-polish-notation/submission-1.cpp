class Solution {
    int performOperation(int val1, int val2, string c){
        if(c == "+")return val1 + val2;
        else if(c == "-")return val1 - val2;
        else if(c == "*")return val1 * val2;
        else return val1/val2;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        for(int i = 0; i<n; i++){
            string s1 = tokens[i];
            if(s1 == "+" || s1 == "-" || s1 == "*" || s1 == "/"){
                int val1 = stoi(st.top());
                st.pop();
                int val2 = stoi(st.top());
                st.pop();

                int ans = performOperation(val2,val1,s1);

                st.push(to_string(ans));
            }
            else{
                st.push(s1);
            }
        }

        return stoi(st.top());
    }
};
