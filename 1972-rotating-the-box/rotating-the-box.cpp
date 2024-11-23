class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> result(n, vector<char>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                result[i][j] = box[j][i];
            }
        }
        for(auto &row:result){
            reverse(row.begin(), row.end());
        }

        for(int j=0; j<m; j++){
            int space = n-1;
            for(int i=n-1; i>=0; i--){
                if(result[i][j] == '*'){
                    space = i-1;
                    continue;
                }

                if(result[i][j] == '#'){
                    result[i][j] = '.';
                    result[space][j] = '#';
                    space--;
                }
            }
        }
        return result;
    }
};