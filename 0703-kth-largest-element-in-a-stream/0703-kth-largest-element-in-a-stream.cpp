class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
        }

        while(minHeap.size() && minHeap.size() > k) {
            minHeap.pop();
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
            return minHeap.top();
        }

        if (val >= minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }
};
