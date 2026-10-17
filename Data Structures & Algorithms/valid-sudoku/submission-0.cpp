class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == '.')continue;
                char val = board[i][j];
                //check row;
                
                for(int k = 0; k<n; k++){
                    if(k == j)continue;
                    if(board[i][k] != '.' && board[i][k] == val)return false;
                }

                // check col

                for(int l = 0; l < n; l++){
                    if(l == i)continue;
                    if(board[l][j] != '.' && board[l][j] == val)return false;
                }
            }
        }


        // now check for 3 * 3

        for(int i = 0; i<n; i+=3){
            for(int j = 0; j<n; j+=3){
                unordered_set<char> st;

                for(int k = i; k<i+3; k++){
                    for(int l = j; l<j+3; l++){
                        if(board[k][l] == '.')continue;
                        if(st.find(board[k][l]) != st.end())return false;

                        st.insert(board[k][l]);
                    }
                }
            }
        }

        return true;
    }
};
