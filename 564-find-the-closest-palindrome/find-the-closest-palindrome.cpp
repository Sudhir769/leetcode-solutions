class Solution {
public:
    long solve(long firstHalf, bool isEven){
        long resultNum = firstHalf;

        if(isEven == false){
            firstHalf /= 10;
        }

        while(firstHalf > 0){
            int digit = firstHalf % 10;
            resultNum = (resultNum * 10) + digit;
            firstHalf /= 10;
        }
        return resultNum;
    }
    string nearestPalindromic(string s) {
        int n = s.length();
        int mid = n/2;

        int firstHalfLength = (n % 2 == 0) ? mid:(mid+1);
        long firstHalf = stol(s.substr(0, firstHalfLength));

        vector<long> possibleResult;
        possibleResult.push_back(solve(firstHalf, n%2 == 0));        
        possibleResult.push_back(solve(firstHalf+1, n%2 == 0));        
        possibleResult.push_back(solve(firstHalf-1, n%2 == 0));        
        possibleResult.push_back((long)pow(10, n-1)-1);        
        possibleResult.push_back((long)pow(10, n)+1);

        long diff = LONG_MAX;
        long result = INT_MAX;
        long originalNum = stol(s);

        for(long num:possibleResult){
            if(num == originalNum) continue;

            if(abs(num - originalNum) < diff){
                diff = abs(num - originalNum);
                result = num;
            }else if(abs(num - originalNum) == diff){
                result = min(result, num);
            }
        }
        return to_string(result);
    }
};