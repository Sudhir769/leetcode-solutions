class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();

        sort(items.begin(), items.end());
        int curr = items[0][1];
        for(int i=1; i<n; i++){
            curr = max(curr, items[i][1]);
            items[i][1] = curr;
        }
        vector<int> result;
        for(auto q:queries){
            int maxi = 0;
            int start = 0, end = n-1;

            while(start <= end){
                int mid = (start + (end - start)/2);

                if(items[mid][0] > q){
                    end = mid - 1;
                }else{
                    maxi = max(maxi, items[mid][1]);
                    start = mid + 1;
                }
            }
            result.push_back(maxi);
        }
        return result;
    }
};