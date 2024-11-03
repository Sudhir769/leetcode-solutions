class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        
        if(m != n){
            return false;
        }

        for(int i=0; i<n; i++){
            rotate(s.begin(), s.begin()+1, s.end());
            if(s.find(goal) != string::npos){
                return true;
            }
        }
        return false;
    }
};