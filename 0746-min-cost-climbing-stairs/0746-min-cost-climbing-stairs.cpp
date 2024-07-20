class Solution {
public:
    vector<int> tab = vector<int>(1001, 0);
    vector<int> minCost = vector<int>(1001, INT_MAX);

    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        stack<pair<int, int>> st;

        st.push({1, cost[1]});
        st.push({0, cost[0]});

        while(!st.empty()){
            auto temp = st.top();
            st.pop();

            if(temp.first + 1 >= size || temp.first + 2 >= size){
                if(temp.second < minCost[temp.first]) 
                    minCost[temp.first] = temp.second;
                continue;
            }

            int first = temp.second + cost[temp.first + 1];
            int second = temp.second + cost[temp.first + 2];

            if(first < minCost[temp.first + 1]){
                minCost[temp.first + 1] = first;
                st.push({temp.first + 1, first});
            }    

            if(second < minCost[temp.first + 2]){
                minCost[temp.first + 2] = second;
                st.push({temp.first + 2, second});
            }    
        }
        
        return min(minCost[cost.size() - 1], minCost[cost.size() - 2]);
    }
};