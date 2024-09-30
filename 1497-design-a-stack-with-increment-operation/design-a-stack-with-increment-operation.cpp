class CustomStack {
public:
    vector<int> st;
    int currSize = 0;
    int maxSize = 0;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(currSize < maxSize){
            st[currSize++] = x;
        }
    }
    
    int pop() {
        if(currSize == 0) return -1;
        else{
            int item = st[currSize-1];
            if(currSize > 0) currSize--;
            return item;
        }
    }
    
    void increment(int k, int val) {
        int index = 0;
        while(k-- > 0 and index < currSize){
            st[index++] += val;
        } 
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */