class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currGreatest = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--){
            if(arr[i] <= currGreatest) arr[i] = currGreatest;
            else swap(arr[i], currGreatest);
            
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};