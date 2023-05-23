class KthLargest {
public:
    int lk;
    priority_queue <int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        lk = k;
        for(auto i : nums){
            add(i);
        }
    }
    
    int add(int val) {
        if(pq.size() < lk){
            pq.push(val);
        }
        else{
            if(pq.top() < val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */