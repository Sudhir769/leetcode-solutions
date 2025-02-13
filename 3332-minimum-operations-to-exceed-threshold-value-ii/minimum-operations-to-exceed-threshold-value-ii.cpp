class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long int, vector<long long int>, greater<long long int>>pq;

        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        int cnt = 0;
        while(pq.size() >= 2){
            long long int x = pq.top(); pq.pop();
            long long int y = pq.top(); pq.pop();

            if(x >= k){
                break;
            }

            long long int newNum = (long long)min(x, y) * 2 + (long long)max(x, y);
            pq.push(newNum);
            cnt++;
        }
        return cnt;
    }
};