class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> help(n, pair<int, int>(0, 0));

        for(int i=0; i<n; i++){
            help[i] = {arr[i], i};
        }

        sort(help.begin(), help.end());
        int rank = 1;
        for(int i=0; i<n; i++){
            int ele = help[i].first;
            int ind = help[i].second;

            if(i > 0 and help[i-1].first == ele) rank--;
            arr[ind] = rank++;
        }
        return arr;
    }
};