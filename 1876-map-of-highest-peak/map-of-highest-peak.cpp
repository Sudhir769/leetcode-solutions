class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    result[i][j] = 0;
                    for(auto dir:directions){
                        int nrow = i + dir[0];
                        int ncol = j + dir[1];

                        if(nrow >= 0 and nrow < m and ncol >=0 and ncol < n 
                            and result[nrow][ncol] != 0){
                            result[nrow][ncol] = 1;
                        }
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 0){
                    int adjMin = INT_MAX;
                    for(auto dir:directions){
                        int nrow = i + dir[0];
                        int ncol = j + dir[1];

                        if(nrow >= 0 and nrow < m and ncol >=0 and ncol < n){
                            adjMin = min(adjMin, result[nrow][ncol]);
                        }
                    }
                    result[i][j] = adjMin == INT_MAX ? INT_MAX-100:adjMin+1;
                }
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(isWater[i][j] == 0){
                    int adjMin = INT_MAX;
                    for(auto dir:directions){
                        int nrow = i + dir[0];
                        int ncol = j + dir[1];

                        if(nrow >= 0 and nrow < m and ncol >=0 and ncol < n){
                            adjMin = min(adjMin, result[nrow][ncol]);
                        }
                    }
                    result[i][j] = adjMin + 1;
                }
            }
        }
        return result;
    }
};
// [[2,1,2,3,2,1,0,1]
// [1,0,1,2,3,2,1,2]
// [2,1,2,3,4,3,2,3]
// [3,2,3,4,5,4,3,4]
// [4,3,3,4,4,3,2,3]
// [4,3,2,3,3,2,1,2]
// [3,2,1,2,2,1,0,1]
// [2,1,0,1,2,2,1,2]]

// [[2,1,2,3,2,1,0,1]
// [1,0,1,2,3,2,1,2]
// [2,1,2,3,4,3,2,3]
// [3,2,3,4,5,4,3,4]
// [4,3,4,5,6,5,2,3]
// [5,4,2,3,4,2,1,2]
// [6,2,1,2,2,1,0,1]
// [2,1,0,1,2,2,1,2]]