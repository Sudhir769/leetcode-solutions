class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>actualIndex(n);
        
        iota(actualIndex.begin(), actualIndex.end(), 0);

        auto lambda = [&](int i, int j){
            return positions[i] < positions[j];
        };

        sort(actualIndex.begin(), actualIndex.end(), lambda);

        vector<int> result;
        stack<int>st;

        for(int &currIdx: actualIndex){
            if(directions[currIdx] == 'R'){
                st.push(currIdx);
            }else{
                while(!st.empty() and healths[currIdx] > 0){
                    int topIdx = st.top();
                    st.pop();

                    if(healths[topIdx] > healths[currIdx]){
                        healths[topIdx]--;
                        healths[currIdx] = 0;
                        st.push(topIdx);
                    }else if(healths[topIdx] < healths[currIdx]){
                        healths[currIdx]--;
                        healths[topIdx] = 0;
                    }else{
                        healths[currIdx] = 0;
                        healths[topIdx]  = 0;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};