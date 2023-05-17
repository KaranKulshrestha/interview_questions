/*
    uname: karankulx
    qname: Course Schedule 
    qlink: https://leetcode.com/problems/course-schedule/
    topic: topological sort
    companies: FANG + Salesforce + Samsung
    rating: medium
*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
        };
        for(int i = 0; i<n; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            };
        };

        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        };
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            };
        };
        if(cnt == n) return true;
        return false;
    }
};