/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        long long lo = 0, hi = n, mid;
        int param;
        
        while(lo < hi){
            mid = (lo + hi)/2;

            param = guess(mid);
            if(param == -1) hi = mid - 1;
            else if(param == 1) lo = mid + 1;
            else return mid;
        }

        return lo;
    }
};