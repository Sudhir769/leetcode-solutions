class Solution {
public:
    void solve(vector<char>& s, int start, int end){
        if(start >= end){
            return;
        }
        swap(s[start], s[end]);
        solve(s, start+1, end-1);
    }
    void reverseString(vector<char>& s) {
        solve(s, 0, s.size()-1);
        return;
    }
};