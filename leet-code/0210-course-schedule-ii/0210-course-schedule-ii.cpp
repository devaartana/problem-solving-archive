class Solution {
public:
    vector<vector<int>> al;
    vector<bool> memo, mark;
    int i;

    bool isDAG(vector<bool> &visited, int vertex){
        if(visited[vertex]) return false;
        
        if(memo[vertex]) return true;

        visited[vertex] = true;

        for(int v:al[vertex]){
            if(!isDAG(visited, v)) return false;
        }

        visited[vertex] = false;
        memo[vertex] = true;
        return true;
    }

    void dfs(vector<int> &result, int vertex){
        mark[vertex] = true;

        for(int v:al[vertex]){
            if(!mark[v]) dfs(result, v);
        }
        
        result[--i] = vertex;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        al = vector<vector<int>>(numCourses, vector<int>());
        mark = memo = vector<bool>(numCourses, false);
        i = numCourses;

        for(auto course:prerequisites){
            al[course[1]].push_back(course[0]);
        }

        vector<int> result(numCourses);
        
        for(int i=0; i < numCourses; i++){
            vector<bool> visited(numCourses, false);
            if(!isDAG(visited, i)){
                return {};
            } else if(!mark[i]){
                dfs(result, i);
            }
        }
        
        return result;
    }
};