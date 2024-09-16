class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0, end = m-1;
        while(start < n and end >= 0){
            int el = matrix[start][end];

            if(el == target){
                return true;
            }else if(el > target){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }
};