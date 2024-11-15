class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();

        int j = n-1;
        while(j > 0 and nums[j] >= nums[j-1]){
            j--;
        }

        int result = j;
        int i=0;
        while(i < j and (i==0 or nums[i] >= nums[i-1])){
            while(j<n and nums[i] > nums[j]){
                j++;
            }
            result = min(result, j-i-1);
            i++;
        }
        return result;
    }
};