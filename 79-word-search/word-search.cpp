class Solution {
public:
    int n, m;

    bool solve(int i, int j, int k, string word, vector<vector<char>>& board){
        if(k == word.length()){
            return true;
        }

        if(i<0 or i>=n or j<0 or j>=m or board[i][j] != word[k]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '\0';

        if(solve(i-1, j, k+1, word, board) or solve(i+1, j, k+1, word, board) or 
            solve(i, j+1, k+1, word, board) or solve(i, j-1, k+1, word, board)){
                return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(solve(i, j, 0, word, board)){
                    return true;
                }
            }
        }
        return false;
    }
};