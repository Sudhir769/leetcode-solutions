class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        for(auto ch:s){
            if(!isdigit(ch)){
                result.push_back(ch);
            }else{
                result.pop_back();
            }
        }
        return result;
    }
};