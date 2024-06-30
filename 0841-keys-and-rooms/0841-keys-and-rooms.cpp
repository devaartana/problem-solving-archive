class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int v = rooms.size(), count = 0;
        vector<bool> visited(v, false);

        stack<int> st;
        st.push(0);

        while(!st.empty()){
            int temp = st.top();
            st.pop();

            if(!visited[temp]){
                visited[temp] = true;
                count++;
            }
            
            for(int vertex:rooms[temp]){
                if(!visited[vertex]) st.push(vertex);
            }   
        }

        return count == v;
    }
};