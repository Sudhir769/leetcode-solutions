class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        string result = "";
        int j=0;
        for(int i=0; i<n; i++){
            string str = s.substr(j, spaces[i]-j);
            j = spaces[i];
            result += str;
            result += " ";
        }
        result += s.substr(j);
        return result;
    }
};