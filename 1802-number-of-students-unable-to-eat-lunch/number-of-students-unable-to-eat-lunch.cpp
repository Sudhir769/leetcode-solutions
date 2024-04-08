class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        vector<int>cnt(2, 0);
        for(int i=0; i<n; i++){
            cnt[students[i]]++;
        }

        for(int i=0; i<n; i++){
            int sand = sandwiches[i];
            if(cnt[sand] == 0){
                return n-i;
            }else{
                cnt[sand]--;
            }
        }
        return 0;
    }
};