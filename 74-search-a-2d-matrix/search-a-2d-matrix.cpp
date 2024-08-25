class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0, end = n*m-1;
        int mid = (start + end)/2;

        while(start <= end){
            mid = (start + end)/2;
            int el = matrix[mid/m][mid%m];
            if(el == target){
                return 1;
            }else if(el > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return 0;
    }
};