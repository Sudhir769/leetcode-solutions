class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        int cnt = 0;
        while(j >= i){
            if(people[i] + people[j] <= limit){
                i++, j--;
                cnt++;
            }else if(people[j] <= limit){
                j--;
                cnt++;
            }else if(people[i] <= limit){
                i++, cnt++;
            }
        }
        return cnt;
    }
};