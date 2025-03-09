class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int cnt = 0;

        for(int i=0, j=1; j<n; j++){
            if(colors[j-1] == colors[j]){
                i=j;
            }

            if(j-i+1 == k){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};