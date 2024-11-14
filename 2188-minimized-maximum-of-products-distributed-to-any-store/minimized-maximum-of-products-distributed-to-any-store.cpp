class Solution {
public:
    bool isPossible(int x, vector<int> &quantities, int shops){

        for(auto &product:quantities){
            shops -= (product + x - 1)/x;

            if(shops < 0) return 0;
        }
        return 1;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int result = 0;
        int left = 1, right = *max_element(quantities.begin(), quantities.end());

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(isPossible(mid, quantities, n)){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
};