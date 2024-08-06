class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> f;
        int key_p = 0;
        int key_position = 1;
        int key_number = 2;
    
        for (char c : word) {
            f[c] = f.find(c) != f.end() ? f[c] + 1 : 1;
        }
    
        vector<char> sorted_chars;
        for (auto const& pair : f) {
            sorted_chars.push_back(pair.first);
        }
        sort(sorted_chars.begin(), sorted_chars.end(), [&f](char a, char b) {
            return f[a] > f[b];
        });
            
            for (char c : sorted_chars) {
            key_p += f[c] * key_position;
            if (key_number < 9) {
                key_number += 1;
            } else {
                key_number = 2;
                key_position += 1;
            }
        }
    
        return key_p;
    }
};