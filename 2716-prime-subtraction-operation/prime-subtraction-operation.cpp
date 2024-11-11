class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        vector<bool> isPrime(1001, true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i<1000; i++){
            if(isPrime[i] == true){
                for(int j=i*i; j<1000; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                continue;
            }

            for(int j=2; j<nums[i]; j++){
                if(!isPrime[j]){
                    continue;
                }

                if(nums[i] - j < nums[i+1]){
                    nums[i] -= j;
                    break;
                }
            }
            if(nums[i] >= nums[i+1]){
                return false;
            }
        }
        return true;
    }
};