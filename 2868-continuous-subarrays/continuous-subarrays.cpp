class Solution {
public:
    #define P pair<int, int>
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P, vector<P>> maxpq;
        priority_queue<P, vector<P>, greater<P>> minpq;

        int i=0, j=0;
        long long cnt = 0;

        while(j < n){

            minpq.push({nums[j], j});
            maxpq.push({nums[j], j});

            while(maxpq.top().first - minpq.top().first > 2){
                i++;
                
                while(!maxpq.empty() and maxpq.top().second < i) maxpq.pop();
                while(!minpq.empty() and minpq.top().second < i) minpq.pop();
            }
            
            cnt += j-i+1;
            j++;
        }

        return cnt;
    }
};