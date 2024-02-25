class DSU {
    vector<int> parent;
    vector<int> size;
    int numberOfComponents;
    
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        numberOfComponents = n;
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int x) {
        if (x == parent[x])
            return x;
            
        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent]  += size[y_parent];
        } else if(size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent]  += size[x_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent]  += size[x_parent];
        }
        
        numberOfComponents -= 1;
    }
    
    int maxSize() {
        return numberOfComponents;
    }
};


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;

        DSU dsu(n);

        for(int i=0; i<n; i++){
            for(int factor=2; factor*factor <= nums[i]; factor++){
                if(nums[i] % factor != 0){
                    continue;
                }
                if(mp.find(factor) != mp.end()){
                    int idx = mp[factor];
                    dsu.Union(idx, i);
                }else{
                    mp[factor] = i;
                }

                while(nums[i] % factor == 0){
                    nums[i] = nums[i]/factor;
                }
            }
            if(nums[i] > 1){
                if(mp.find(nums[i]) != mp.end()){
                    int idx = mp[nums[i]];
                    dsu.Union(idx, i);
                }else{
                    mp[nums[i]] = i;
                }
            }
        }
        return dsu.maxSize() == 1;
    }
};
