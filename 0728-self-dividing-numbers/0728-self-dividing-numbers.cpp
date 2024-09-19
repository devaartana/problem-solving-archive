class Solution {
public:
    bool isSelfDividing(int num) {
        int temp;
        for (int i = num; i; i /= 10) {
            temp = i % 10;
            if (!temp || num % temp) return false;
            
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if ((isSelfDividing(i)))
                ans.push_back(i);
        }
        return ans;
    }
};