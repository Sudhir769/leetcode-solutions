class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        
        sort(happiness.begin(), happiness.end());
        int i = n;
        long long result = 0;
        int dec = 0;
        while(i-- and k>0){
            if(happiness[i] - dec > 0){
                result += (happiness[i]-dec); //[1,2,3]
                dec++;
                k--;
            }
        }
        return result;
    }
};