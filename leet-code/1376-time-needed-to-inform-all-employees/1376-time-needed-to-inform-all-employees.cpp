class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<bool> visited(n, false);
        int count=0;
        for(int employee : manager){
            if(employee != -1 && !visited[employee]){
                count += informTime[employee];
                visited[employee] = true;
            }
        }

        return count;
    }
};