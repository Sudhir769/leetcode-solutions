class MedianFinder {
public:
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftMax.push(num);
            
        int top = leftMax.top();
        leftMax.pop();
        
        rightMin.push(top);
        
        if(rightMin.size() > leftMax.size()){
            int el = rightMin.top();
            rightMin.pop();
            
            leftMax.push(el);
        }
    }
    
    double findMedian() {
        if(leftMax.size() != rightMin.size()){
            return leftMax.top();
        }else{
            return double(leftMax.top() + rightMin.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */