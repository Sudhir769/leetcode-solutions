class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int score = 0;
        int maxi = values[0] + 0;
        for(int i=1; i<n; i++){
            score = max(score, maxi + values[i]-i);
            maxi = max(maxi, values[i] + i);
        }
        return score;
    }
};