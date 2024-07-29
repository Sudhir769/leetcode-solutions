class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        for(int j=1; j<n-1; j++){
            int cntSmallerLeft = 0;
            int cntLargerLeft = 0;
            int cntSmallerRight = 0;
            int cntLargerRight = 0;

            for(int i=0; i<j; i++){
                if(rating[i] < rating[j]){
                    cntSmallerLeft++;
                }else if(rating[i] > rating[j]){
                    cntLargerLeft++;
                }
            }

            for(int k=j+1; k<n; k++){
                if(rating[j] < rating[k]){
                    cntLargerRight++;
                }else if(rating[j] > rating[k]){
                    cntSmallerRight++;
                }
            }
            teams += (cntLargerLeft * cntSmallerRight) + (cntLargerRight * cntSmallerLeft);
        }
        return teams;
    }
};