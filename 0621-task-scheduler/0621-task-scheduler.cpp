#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        auto cmp = [&freq](int a, int b) { return freq[a] < freq[b]; };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i])
                pq.push(i);
        }

        queue<pair<int, int>> q;

        int counter = 0;
        while (!pq.empty() || !q.empty()) {
            if (!q.empty() && q.front().second + n < counter) {
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()) {
                int temp = pq.top();
                pq.pop();

                if (--freq[temp]) {
                    q.push({temp, counter});
                }
            } 

            counter++;
        }

        return counter;
    }
};
