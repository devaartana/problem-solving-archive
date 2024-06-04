class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size = arr.size();
        
        if(size < 2) return false;
        
        for(int i=0; i < size - 2; i++){
            if(arr[i]&1 && arr[i+1]&1 && arr[i+2]&1) return true;
        }

        return false;    
    } 
};