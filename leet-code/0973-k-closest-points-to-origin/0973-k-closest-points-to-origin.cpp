class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return sqrt(a[0] * a[0] + a[1] * a[1]) <
                   sqrt(b[0] * b[0] + b[1] * b[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);
        for (vector<int>& point : points) {
            maxHeap.push(point);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }
};
