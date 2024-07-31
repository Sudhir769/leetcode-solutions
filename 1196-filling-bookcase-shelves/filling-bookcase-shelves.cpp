class Solution {
public:
    int n;
    int WIDTH;
    int t[1000][10001];

    int solve(vector<vector<int>>& books, int i, int remWidth, int maxHt){
        if(i >= n){
            return maxHt;
        }

        if(t[i][remWidth] != -1){
            return t[i][remWidth];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(bookW <= remWidth){
            keep = solve(books, i+1, remWidth - bookW, max(maxHt, bookH));
        }

        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);

        return t[i][remWidth] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;

        int remWidth = shelfWidth;
        return solve(books, 0, remWidth, 0);
    }
};