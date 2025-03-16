class Solution {
public:
    bool isPossible(long long mid, vector<int>& ranks, int cars, int n){

        long long carFixed = 0;
        for(int i=0; i<n; i++){
            carFixed = sqrt(mid/ranks[i]);

            cars -= carFixed;
            if(cars <= 0){
                return true;
            }
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        int maxi = *max_element(ranks.begin(), ranks.end());
        long long left = 1, right = 1LL* maxi * cars * cars;

        long long result = 0;
        while(left <= right){
            long long mid = left + (right - left)/2;

            if(isPossible(mid, ranks, cars, n)){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
};