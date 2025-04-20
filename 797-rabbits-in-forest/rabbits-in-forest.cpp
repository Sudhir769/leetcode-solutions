class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(auto ans:answers){
            mp[ans]++;
        }
        int total = 0;
        for(auto it:mp){
            int x = it.first;
            int cnt = it.second;

            int groupSize = x+1;
            int groups = ceil((double)cnt/groupSize);

            total += groups * (groupSize);
        }
        return total;
    }
};