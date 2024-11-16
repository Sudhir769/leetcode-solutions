class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result;
        for(int i=0; i<n-k+1; i++){
            bool flag = true;
            for(int j=i; j<k-1+i; j++){
                if(nums[j] >= nums[j+1]){
                    flag = false;
                    break;
                }
            }
            if(flag and abs(nums[i+k-1] - nums[i]) < k){
                result.push_back(nums[i+k-1]);
            }else{
                result.push_back(-1);
            }
        }
        return result;
    }
};