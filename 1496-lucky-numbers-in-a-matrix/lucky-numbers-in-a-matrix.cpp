class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            int minIdx = -1, minEle = INT_MAX;

            for(int j=0; j<m; j++){
                if(matrix[i][j] < minEle){
                    minIdx = j;
                    minEle = matrix[i][j];
                }
            }
            bool found = 1;
            for(int k=0; k<n; k++){
                if(matrix[i][minIdx] < matrix[k][minIdx]){
                    found = 0;
                    break;
                }
            }
            if(found) ans.push_back(minEle);
        }
        
        return ans;
    }
};