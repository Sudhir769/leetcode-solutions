class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        s = s + s;
        
        if(m != n){
            return false;
        }
        if(s.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};