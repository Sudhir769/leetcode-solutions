class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> cumSum(n, 0);

        int result = INT_MAX;
        int j = 0;

        while(j < n){
            if(j == 0){
                cumSum[j] = nums[j];
            }else{
                cumSum[j] = cumSum[j-1] + nums[j];
            }

            if(cumSum[j] >= k){
                result = min(result, j+1);
            }

            while(!dq.empty() and cumSum[j] - cumSum[dq.front()] >= k){
                result = min(result, j - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() and cumSum[j] <= cumSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return result == INT_MAX ? -1:result;
    }
};