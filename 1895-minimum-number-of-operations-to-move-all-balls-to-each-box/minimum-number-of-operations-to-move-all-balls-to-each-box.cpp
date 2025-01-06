class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ans(n, 0);

        int cumValue = 0;
        int cumSum = 0;

        int cumValueLeft = 0;
        int cumSumLeft = 0;
        for(int i=0; i<n; i++){
            ans[i] += cumSum;
            cumValue += (boxes[i] == '0' ? 0:1);
            cumSum += cumValue;

            ans[n-i-1] += cumSumLeft;
            cumValueLeft += (boxes[n-1-i] == '0' ? 0:1);
            cumSumLeft += cumValueLeft;
        }
        return ans;
    }
};