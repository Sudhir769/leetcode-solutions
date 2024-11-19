class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0, j=0;
        long long result = 0;
        long long currSum = 0;

        unordered_set<int> st;

        while(j < n){
            while(st.count(nums[j])){
                currSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            currSum += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                result = max(result, currSum);
                currSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};