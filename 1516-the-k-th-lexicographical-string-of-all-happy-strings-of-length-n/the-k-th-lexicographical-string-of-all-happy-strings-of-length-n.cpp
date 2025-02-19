class Solution {
public:
    vector<string> ans;
    void solve(int n, string& temp){
        if(temp.length() == n){
            ans.push_back(temp);
            return;
        }

        for(char ch='a'; ch<='c'; ch++){
            if(!temp.empty() and temp.back() == ch) continue;

            temp.push_back(ch);
            solve(n, temp);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string temp = "";
        solve(n, temp);
        if(ans.size() < k) return "";
        return ans[k-1];
    }
};