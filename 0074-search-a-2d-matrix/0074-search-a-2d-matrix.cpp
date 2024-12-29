class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() * matrix[0].size() - 1, n = matrix[0].size();

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2, rmid = mid/n, cmid = mid%n;

            if(matrix[rmid][cmid] > target) {
                hi = mid - 1;
            } else if (matrix[rmid][cmid] < target) {
                lo = mid + 1;
            } else return true;
        }

        return false;
    }
};