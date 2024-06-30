class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int v = rooms.size(), count = 1;
        vector<bool> visited(v, false);

        stack<int> st;
        st.push(0);

        while(!st.empty()){
            int temp = st.top();
            st.pop();

            visited[temp] = true;
            
            for(int vertex:rooms[temp]){
                if(!visited[vertex]){
                    count++;
                    st.push(vertex);
                }
            }   
        }

        return count >= v;
    }
};