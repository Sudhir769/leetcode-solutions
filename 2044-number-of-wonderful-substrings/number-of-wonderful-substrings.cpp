class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        int currXor = 0;
        long long result = 0;

        for(auto &ch: word){
            int shift = ch - 'a';
            currXor ^= (1 << shift);

            result += mp[currXor];

            for(char ch1 = 'a'; ch1 <= 'j'; ch1++){
                shift = ch1 - 'a';
                long long check_xor = (currXor^(1 << shift));
                result += mp[check_xor];
            }
            mp[currXor]++;
        }
        return result;
    }
};