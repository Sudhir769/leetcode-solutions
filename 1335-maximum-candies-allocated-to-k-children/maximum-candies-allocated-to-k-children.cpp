class Solution {
public:
    bool canDistribute(int candy, vector<int>& candies, long long k, int n){

        for(int i=0; i<n; i++){
            k -= (candies[i]/candy);
            if(k <= 0) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        long long total = 0;
        int maxCan = 0;

        for(auto candy:candies){
            maxCan = max(maxCan, candy);
            total += candy;
        }

        if(total < k) return 0;
        else if(total == k) return 1;

        int left = 1, right = maxCan;
        int result = 0;
        while(left <= right){
            int mid = (left + right)/2;

            if(canDistribute(mid, candies, k, n)){
                result = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
};