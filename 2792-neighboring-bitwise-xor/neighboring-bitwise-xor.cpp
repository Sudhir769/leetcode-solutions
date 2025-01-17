class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int n = derived.size(); 
        int ones = 0;
        for(auto num:derived){
            ones += num;
        }
        if(ones % 2 == 0) return true;
        return false;
    }
};
