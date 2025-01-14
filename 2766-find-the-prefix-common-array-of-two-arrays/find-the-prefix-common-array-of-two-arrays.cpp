class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n, 0);
        unordered_map<int, int> mp;

        int cnt = 0;
        for(int i=0; i<n; i++){
            mp[A[i]]++;
            cnt += mp[A[i]] == 2;

            mp[B[i]]++;
            cnt += mp[B[i]] == 2;

            result[i] = cnt;
        }
        return result;
    }
};