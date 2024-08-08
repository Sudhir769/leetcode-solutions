class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0,-1}, {-1, 0}};

        vector<vector<int>> result;

        int steps = 0, dir = 0;
        result.push_back({rStart, cStart});

        while(result.size() < rows*cols){
            if(dir == 0 or dir == 2){
                steps++;
            }
            for(int cnt=0; cnt<steps; cnt++){
                rStart +=directions[dir][0];
                cStart += directions[dir][1];

                if(rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};