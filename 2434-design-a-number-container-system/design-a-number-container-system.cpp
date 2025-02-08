class NumberContainers {
public:
    unordered_map<int, int> indToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToInd;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        indToNum[index] = number;
        numToInd[number].push(index);
    }
    
    int find(int number) {
        
        if(numToInd.find(number) != numToInd.end()){
            auto& pq = numToInd[number];

            while(!pq.empty()){
                int index = pq.top();
                if(indToNum[index] == number){
                    return index;
                }else{
                    pq.pop();
                }
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */