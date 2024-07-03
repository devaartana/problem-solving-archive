class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int size = arr.size();
        vector<bool> visited(size, false);
        
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            if(!arr[temp]) return true;

            int lo = temp - arr[temp], hi = temp + arr[temp]; 
            if(lo >= 0 && !visited[lo]) {
                q.push(lo);
                visited[lo] = true;
            }

            if(hi < size && !visited[hi]) {
                q.push(hi);
                visited[hi] = true;    
            }
        }

        return false;
    }
};