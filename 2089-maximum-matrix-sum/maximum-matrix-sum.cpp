class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        long long maxSum = 0;
        int neg = 0;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                maxSum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));

                if(matrix[i][j] < 0){
                    neg++;
                }
            }
        }
        if(neg % 2){
            maxSum -= 2*mini;
        }
        return maxSum;
    }
};