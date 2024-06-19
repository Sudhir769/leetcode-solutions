class Solution {
public:
    int solve(vector<int>& bloomDay, int mid, int k){
        int count = 0;
        int consecutive = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consecutive++;
            }else{
                consecutive = 0;
            }

            if(consecutive == k){
                count++;
                consecutive = 0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start_day = 0;
        int end_day   = *max_element(bloomDay.begin(), bloomDay.end());

        int minDays = -1;

        while(start_day <= end_day){
            int mid = start_day + (end_day - start_day)/2;

            if(solve(bloomDay, mid, k) >= m){
                minDays = mid;
                end_day = mid-1;
            }else{
                start_day = mid+1;
            }
        }
        return minDays;
    }
};