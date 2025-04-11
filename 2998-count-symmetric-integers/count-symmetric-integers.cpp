class Solution {
public:
     bool isSymmetric(int num) {
        string s = to_string(num);
        int length = s.length();
        
        if (length % 2 != 0) {
            return false;
        }
        
        int half = length / 2;
        int firstHalfSum = 0;
        int secondHalfSum = 0;
        
        for (int i = 0; i < half; i++) {
            firstHalfSum += s[i] - '0';
        }
    
        for (int i = half; i < length; i++) {
            secondHalfSum += s[i] - '0';
        }
        
        return firstHalfSum == secondHalfSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; num++) {
            if (isSymmetric(num)) {
                count++;
            }
        }
        return count;
    }
};