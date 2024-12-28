class Solution {
public:
    int t[20001][4];
    int helper(vector<int> &subarray, int cnt, int i, int k){
        if(cnt == 0) return 0;
        if(i >= subarray.size()) return INT_MIN;

        if(t[i][cnt] != -1) return t[i][cnt];

        int take = subarray[i] + helper(subarray, cnt-1, i+k, k);
        int notTake = helper(subarray, cnt, i+1, k);

        return t[i][cnt] = max(take, notTake);
    }
    void solve(vector<int>& subarray, int cnt, int i, int k, vector<int>& result){
        if(cnt == 0 or i >= subarray.size()) return;

        int take = subarray[i] + helper(subarray, cnt-1, i+k, k);
        int notTake = helper(subarray, cnt, i+1, k);

        if(take >= notTake){
            result.push_back(i);
            solve(subarray, cnt-1, i+k, k, result);
        }else{
            solve(subarray, cnt, i+1, k, result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        memset(t, -1, sizeof(t));
        vector<int> subarray;
        int i=0, j=0;
        int currSum = 0;
        while(j < n){
            currSum += nums[j];

            if(j-i+1 == k){
                subarray.push_back(currSum);
                currSum -= nums[i];
                i++;
            }
            j++;
        }       
        
        vector<int> result;
        solve(subarray, 3, 0, k, result);
        return result;
    }
};