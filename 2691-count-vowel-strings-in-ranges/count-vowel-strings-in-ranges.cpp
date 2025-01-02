class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();;
        int m = queries.size();

        vector<int> prefix(n, 0), result(m, 0);
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        int sum = 0;
        for(int i=0; i<n; i++){
            if(st.count(words[i][0]) and st.count(words[i].back())){
                sum++;
            }
            prefix[i] = sum;
        }
        
        for(int i=0; i<m; i++){
            auto query = queries[i];

            int left = query[0];
            int right = query[1];

            result[i] = prefix[right] - (left > 0 ? prefix[left-1]:0);
        }
        return result;
    }
};