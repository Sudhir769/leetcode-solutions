class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";

        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }
        queue<string> q;
        q.push(start);
        
        string target = "123450";
        unordered_set<string> vis;
        vis.insert(start);

        unordered_map<int, vector<int>> dir;
        dir[0] = {1, 3};
        dir[1] = {0, 2, 4};
        dir[2] = {1, 5};
        dir[3] = {0, 4};
        dir[4] = {1, 3, 5};
        dir[5] = {2, 4};

        int level = 0;
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target){
                    return level;
                }

                int currIndex = curr.find('0');
                for(auto newIndex:dir[currIndex]){
                    string newState = curr;
                    swap(newState[currIndex], newState[newIndex]);

                    if(vis.find(newState) == vis.end()){
                        q.push(newState);
                        vis.insert(newState);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};