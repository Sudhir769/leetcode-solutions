class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int i = 0, posIndex = 0, negIndex = 1;
        while(i<n){
            if(nums[i] > 0){
                ans[posIndex] = nums[i];
                posIndex += 2;
            }else{
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            i++;
        }
        return ans;
    }
};