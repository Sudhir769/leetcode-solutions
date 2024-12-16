class Solution {
public:
    #define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto it = pq.top();
            pq.pop();

            int num = it.first;
            int ind = it.second;

            pq.push({num*multiplier, ind});
        }

        while(!pq.empty()){
             auto it = pq.top();
            pq.pop();

            int num = it.first;
            int ind = it.second;

            nums[ind] = num;
        }
        return nums;
    }
};