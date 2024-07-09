class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double resultTime = 0;
        int currTime = 0;

        for(auto vec:customers){
            int arrivalTime = vec[0];
            int cookTime        = vec[1];

            if(currTime < arrivalTime){
                currTime = arrivalTime;
            }

            int timeTaken = (currTime + cookTime - arrivalTime);
            resultTime += timeTaken;

            currTime += cookTime;
        }
        return resultTime/n;
    }
};