class Solution {
public:
    vector<vector<int>> al;
    vector<bool> memo;

    bool dfs(vector<bool> &visited, int vertex){
        if(visited[vertex]) return false;
        
        if(!memo[vertex]) memo[vertex] = true;

        visited[vertex] = true;

        for(int v:al[vertex]){
            if(!dfs(visited, v)) return false;
        }

        visited[vertex] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memo = vector<bool>(numCourses, false);
        al = vector<vector<int>>(numCourses, vector<int>());

        for(auto course:prerequisites){
            al[course[1]].push_back(course[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(!memo[i]){
                
                vector<bool> visited(numCourses, false);

                if(!dfs(visited, i)) return false;
            }
        }

        return true;
    }
};