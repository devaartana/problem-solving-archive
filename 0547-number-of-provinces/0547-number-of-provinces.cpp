class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int count = 0, maxI = isConnected.size(), temp;
        vector<bool> visited(maxI, false);
        
        stack<int> st;
        for(int i=0; i<maxI; i++){
            if(!visited[i]){
                count++;

                st.push(i);
                visited[i] = true;
                while(!st.empty()){
                    temp = st.top();
                    st.pop();

                    if(!visited[temp]){
                        visited[temp] = true;
                    }

                    for(int j=0; j<maxI; j++){
                        if(isConnected[temp][j] && !visited[j]){
                            st.push(j);
                        }
                    }

                }
            }
        }

        return count;    
    }
};