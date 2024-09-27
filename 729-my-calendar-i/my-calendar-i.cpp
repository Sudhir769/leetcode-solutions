class MyCalendar {
public:
    unordered_map<int, int> um;
    MyCalendar() {

    }
    
    bool book(int x, int y) {
        for(auto& val : um) {
            int a = val.first, b = val.second;

            if(!(y <= a || x >= b)) {
                return false;
            }
        }
        um[x] = y;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */