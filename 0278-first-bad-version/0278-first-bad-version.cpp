// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;

        while(lo < hi){
            int mid = (hi - lo)/2 + lo;
            bool statusMid = isBadVersion(mid), beforeMid = isBadVersion(mid - 1);
            if(statusMid && !beforeMid) return mid;
            else if(statusMid) hi = mid - 1;
            else lo = mid + 1;
        }

        return lo;
    }
};