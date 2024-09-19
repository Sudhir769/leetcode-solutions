class Solution {
public:
    vector<int> solve(string s){
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '+' or s[i] == '-' or s[i] == '*'){
                auto left = solve(s.substr(0, i));
                auto righ = solve(s.substr(i+1));
                
                for(auto &x:left){
                    for(auto &y: righ){
                        if(s[i] == '+'){
                            ans.push_back(x+y);
                        }else if(s[i] == '-'){
                            ans.push_back(x-y);
                        }else{
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};