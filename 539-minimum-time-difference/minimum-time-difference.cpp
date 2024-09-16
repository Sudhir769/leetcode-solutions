class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        
        vector<int> minTime(n);

        int result = INT_MAX;
        for(int i=0; i<n; i++){
            string time = timePoints[i];
            
            int timeInMin = stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
            minTime[i] = timeInMin;
        }
        sort(minTime.begin(), minTime.end());

        for(int i=0; i<n-1; i++){
            result = min(result, minTime[i+1] - minTime[i]);
        }
        return min(result, 24*60 - minTime[n-1] + minTime[0]);
    }
};